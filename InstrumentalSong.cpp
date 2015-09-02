#include "InstrumentalSong.h"

/**
 * Documented in header file.
 */
InstrumentalSong::InstrumentalSong(vector<string> &title, map<string, int> &tags,
                                   vector<string> &instruments, vector<string> &performedBy,
                                   map<string, int> &mood)
{
//	todo add nullptr verification
	this->_title = title;
	this->_tags = tags;
	this->_instruments = instruments;
	this->_performedBy = performedBy;
	this->_mood = mood;
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
const map<string, int> &InstrumentalSong::getMood() const
{
	return _mood;
}

/**
 * Documented in header file.
 */
void InstrumentalSong::setMood(const map<string, int> &_mood)
{
	InstrumentalSong::_mood = _mood;
}