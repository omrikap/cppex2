// Manager.cpp

// todo 5. implement bpmToMood.
// todo 6. implement calculateScore
// todo 7. decide on sorting method.

#include <sstream>
#include <math.h>
#include "Manager.h"
#include "Song.h"
#include "LyricalSong.h"
#include "InstrumentalSong.h"

#define EMPTY_LINE 4
const string TAG_MATCH = "tagMatchScore";
const string LYRICS_MATCH = "lyricsMatchScore";
const string INSTRUMENT_MATCH = "instrumentMatchScore";
const string BPM_LIKELIHOOD = "bpmLikelihoodWeight";

Manager::Manager()
{
	_theSongs = new list<Song>();
}


Manager::~Manager()
{
	if (_theSongs != nullptr)
	{
		delete _theSongs;
	}
}

/*
 * documented in the header.
 */
vector<string>& Manager::stringToVector(const string &theString)
{
	// Put the string in a string stream object to iterate on words.
	istringstream *iss = new istringstream(theString);

	// Create a vector to put words in. Dynamic because size unknown.
	vector<string> *result = new vector<string>();

	while (*iss)
	{
		string word;
		*iss >> word;

		// don't push empty strings from the vector
		if (word != "")
		{
			result->push_back(word);
		}
	}

	return *result;
}

/*
 * documented in the header.
 */
map<string, int>& Manager::stringToMap(const string &theString)
{
	// Put the string in a string stream object to iterate on words.
	istringstream *iss = new istringstream(theString);

	// Create a vector to put words in. Dynamic because it's size is unknown.
	map<string, int> *result = new map<string, int>();

	while (*iss)
	{
		string word;
		string weight;
		*iss >> word;
		*iss >> weight;

		// stoi can't get empty string.
		if (weight != "" || word != "")
		{
			result->insert(std::pair<string,int>(word, stoi(weight, nullptr)));
		}
	}

	return *result;
}

/*
 * documented in the header.
 */
std::string Manager::getWordList(const std::string line)
{
	size_t pos1 = line.find("{");
	size_t pos2 = line.find("}");

	return line.substr(pos1+1,pos2-pos1-1);
}

/**
 * documented in header file.
 */
list<Song> * Manager::readSongsFromFile(std::string songsFileName)
{
	// this is where the Song objects parsed from the file will be stored.
//	vector<Song> *_theSongs = new vector<Song>();

	std::ifstream instream(songsFileName.c_str());
	if (!instream.is_open())
	{
		std::cerr << "Error! Can't open file: " << songsFileName << "." << std::endl;
	}

	std::string line = "";

	int lastSong = 0;

	while(instream.good() && !lastSong)
	{
		if (line.compare(SEPARATOR) != 0)
		{
			getline(instream, line);
			// Expect a line of "="
			if (END_OF_SONGS.compare(line) == 0)
			{
				lastSong = 1;
				break;
			}
		}

		getline(instream, line);
		// Expect a line of "title: ..."
		size_t pos = TITLE.size() + 2;
		std::string title = line.substr(pos);

		getline(instream, line);
		// Expect a line of "tags: {...}"
		std::string tags = getWordList(line);

		std::string lyrics = "";
		std::string lyricsBy = "";
		std::string instruments = "";
		std::string performedBy = "";
		std::string bpmStr = "";
		map<string, double> * moodMap = nullptr;

		getline(instream, line);
		// Expect either lyrics or instruments.
		if (line.substr(0, LYRICS.size()).compare(LYRICS) == 0)
		{
			// Then we have a lyric song

			// Lets get the lyrics:
			lyrics = getWordList(line);

			// Lets get the lyricsBy:
			getline(instream, line);
			pos = LYRICS_BY.size() + 2;
			lyricsBy = line.substr(pos);

			LyricalSong *lyricalSong = new LyricalSong(stringToVector(title), stringToMap(tags),
			                                           stringToVector(lyrics),
			                                           stringToVector(lyricsBy));
			this->_theSongs->push_back(*lyricalSong);
		}
		else
		{
			// Then we have an instrumental song

			// Lets get the instruments:
			instruments = getWordList(line);

			// Lets get the performedBy:
			getline(instream, line);
			pos = PERFORMED_BY.size() + 2;
			performedBy = line.substr(pos);

			// Lets see if we have bpm:
			if (!instream.good())
			{
				break;
			}
			getline(instream, line);
			if (END_OF_SONGS.compare(line) == 0)
			{
				lastSong = 1;
			}


			if (line.substr(0, BPM.size()).compare(BPM) == 0)
			{

				pos = BPM.size() + 2;
				bpmStr = line.substr(pos);
				moodMap = bpmToMood(bpmStr);

				// TODO what happens with bpm.
			}
			else
			{
				assert ( (line.compare(SEPARATOR) == 0) || (line.compare(END_OF_SONGS) == 0));

				// TODO what happens if no bpm?
			}
			InstrumentalSong *instrumentalSong = new InstrumentalSong(stringToVector(title),
			                                                          stringToMap(tags),
			                                                          stringToVector(instruments)
					,stringToVector(performedBy), *moodMap);
			this->_theSongs->push_back(*instrumentalSong);
		}
	}
	instream.close();
	return _theSongs;
}

void Manager::readParametersFromFile(string parametersFileName)
{
	_parameters = new Parameters();
	vector<Mood> *moods = new vector<Mood>();

	std::ifstream instream(parametersFileName.c_str());
	if (!instream.is_open())
	{
		std::cerr << "Error! Can't open file: " << parametersFileName << "." << std::endl;
	}

	std::string line = "";

	size_t pos = 0;

	// expecting to get the four weights by the format order.
	getline(instream, line);
	pos = TAG_MATCH.size() + 2;
	_parameters->set_tagMatchScore(stoi(line.substr(pos)));

	getline(instream, line);
	pos = LYRICS_MATCH.size() + 2;
	_parameters->set_lyricsMatchScore(stoi(line.substr(pos)));

	getline(instream, line);
	pos = INSTRUMENT_MATCH.size() + 2;
	_parameters->set_instrumentsMatchScore(stoi(line.substr(pos)));

	getline(instream, line);
	pos = BPM_LIKELIHOOD.size() + 2;
	_parameters->set_bpmLikeMatchScore(stoi(line.substr(pos)));

	// get the moods from the file lines
	while(getline(instream, line))
	{
		if (line.compare("") == 0)
		{
			// skip empty lines
			continue;
		}
		Mood * mood = new Mood();

		pos = line.find(":");
		mood->setName(line.substr(0, pos));
		line.erase(0, pos + 2);
		assert(line.substr(0, ' ') != "");
		mood->setAverage(stof(line.substr(0, ' ')));
		line.erase(0, line.find(' ') + 3);
		assert(line.substr(0, ' ') != "");
		mood->setDeviation(stof(line.substr(0)));

		moods->push_back(*mood);
	}
	instream.close();
	_parameters->set_moods(moods);
}

map<string, double>* Manager::bpmToMood(string& bpm)
{
	map<string, double>* moods = new map<string, double>();
	for (int i = 0; i < _parameters->get_moods().size(); ++i)
	{
		double weight = floor(exp(((pow(stoi(bpm) - _parameters->get_moods()[i].getAverage(), 2) /
		2 * pow(_parameters->get_moods()[i].getDeviation(), 2)))));
		moods->insert(pair<string, double>(_parameters->get_moods()[i].getName(), weight));
	}
	return moods;
}
