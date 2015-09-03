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
int InstrumentalSong::calculateScore()
{
	cout << this->_score; //todo remove
	return Song::calculateScore();
}

/**
 * Documented in header file.
 */
const vector<string> &InstrumentalSong::getInstruments() const
{
	return _instruments;
}

/**
 * Documented in header file.
 */
void InstrumentalSong::setInstruments(const vector<string> &_instruments)
{
	InstrumentalSong::_instruments = _instruments;
}

/**
 * Documented in header file.
 */
const vector<string> &InstrumentalSong::getPerformedBy() const
{
	return _performedBy;
}

/**
 * Documented in header file.
 */
void InstrumentalSong::setPerformedBy(const vector<string> &_performedBy)
{
	InstrumentalSong::_performedBy = _performedBy;
}

/**
 * Documented in header file.
 */
 void InstrumentalSong::setMood(map<string, int> &mood)
{
	InstrumentalSong::_mood = mood;
}

/**
 * Documented in header file.
 */
map<string, int> InstrumentalSong::getMood() const
{
	return _mood;
}