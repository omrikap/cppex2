#include "InstrumentalSong.h"

/**
 * Documented in header file.
 */
InstrumentalSong::InstrumentalSong(vector<string> &title, map<string, int> &tags,
                                   vector<string> &instruments, vector<string> &performedBy,
                                   map<string, int> &mood)
{
//	todo add nullptr verification
	_title = title;
	_tags = tags;
	_instruments = instruments;
	_performedBy = performedBy;
	_mood = mood;
}

/**
 * Documented in header file.
 */
InstrumentalSong::InstrumentalSong(vector<string> &title, map<string, int> &tags,
                                   vector<string> &instruments, vector<string> &performedBy)
{
//	todo add nullptr verification
	_title = title;
	_tags = tags;
	_instruments = instruments;
	_performedBy = performedBy;
}

/**
 * Documented in header file.
 */
void InstrumentalSong::calculateScore(string &query, Parameters parameters)
{
	int tagScore = 0;
	int instruments = 0;
	int mood = 0;

	tagScore = _tags[query] * parameters.get_tagMatchScore();

	if (std::find(_instruments.begin(), _instruments.end(), query) != _instruments.end())
	{
		instruments = parameters.get_lyricsMatchScore();
	}

	if (std::find(parameters.get_moods().begin(), parameters.get_moods().end(), query) !=
			parameters.get_moods().end())
	{
		double m = parameters.get_moods()[i].getAverage();
		double s = parameters.get_moods()[i].getDeviation();
		double bpm = stoi(_strBpm);
		double exponentValue = exp(-1 * (pow((bpm - m), 2.0)) / (2.0 * pow(s, 2.0)));
		mood =
	}

	_score = tagScore + instruments;
	cout << this->_score; //todo remove
}
