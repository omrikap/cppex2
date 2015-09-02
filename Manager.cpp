// Manager.cpp

// todo 4. parse the parameters file.
// todo 5. implement bpmToMood.
// todo 6. implement calculateScore
// todo 7. decide on sorting method.

#include <sstream>
#include "Manager.h"
#include "Song.h"
#include "LyricalSong.h"
#include "InstrumentalSong.h"

#define WEIGHTS 4
#define TAG_MATCH "tagMatchScore:"
#define LYRICS_MATCH "lyricsMatchScore:"

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
		std::string moodStr = "sad 10"; // todo remove. Temporary to prevent crash.

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
//				string moodString = bpmToMood(bpmStr); fixme

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
					,stringToVector(performedBy), stringToMap(moodStr));
			this->_theSongs->push_back(*instrumentalSong);
		}
	}
	instream.close();
	return _theSongs;
}

void Manager::readParametersFromFile(string parametersFileName)
{
	std::ifstream instream(parametersFileName.c_str());
	if (!instream.is_open())
	{
		std::cerr << "Error! Can't open file: " << parametersFileName << "." << std::endl;
	}

	std::string line = "";

	for (int i = 0; i < WEIGHTS; ++i)
	{
		getline(instream, line);
		cout << line << endl; // todo remove

//		std::vector<std::string> &split(const std::string &s, char delim,std::vector<std::string> &elems) {
//			std::stringstream ss(s);
//			std::string item;
//			while (std::getline(ss, item, delim)) {
//				if (item.length() > 0) {
//					elems.push_back(item);
//				}
//			}
//			return elems;
//		}
//
//
//		std::vector<std::string> split(const std::string &s, char delim) {
//			std::vector<std::string> elems;
//			split(s, delim, elems);
//			return elems;
//		}
	}

	while(getline(instream, line))
	{
		if (line.compare("") == 0)
		{
			// skip empty lines
			continue;
		}

		getline(instream, line);
		// Expect a line of "title: ..."
		size_t pos = TITLE.size() + 2;
		std::string title = line.substr(pos);

		getline(instream, line);
		// Expect a line of "tags: {...}"
		std::string tags = getWordList(line);
	}
	instream.close();
}
