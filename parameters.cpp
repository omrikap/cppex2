// todo change getters/setters names

#include "parameters.h"

/**
 * documented in header file.
 */
Parameters::Parameters()
{
	_moods = new vector<Mood>();
}

/**
 * documented in header file.
 */
Parameters::~Parameters()
{
	if (_moods != nullptr)
	{
		delete _moods;
	}
}

/**
 * documented in header file.
 */
int Parameters::get_tagMatchScore() const
{
	return _tagMatchScore;
}

/**
 * documented in header file.
 */
void Parameters::set_tagMatchScore(int _tagMatchScore)
{
	Parameters::_tagMatchScore = _tagMatchScore;
}

/**
 * documented in header file.
 */
int Parameters::get_lyricsMatchScore() const
{
	return _lyricsMatchScore;
}

/**
 * documented in header file.
 */
void Parameters::set_lyricsMatchScore(int _lyricsMatchScore)
{
	Parameters::_lyricsMatchScore = _lyricsMatchScore;
}

/**
 * documented in header file.
 */
int Parameters::get_instrumentsMatchScore() const
{
	return _instrumentsMatchScore;
}

/**
 * documented in header file.
 */
void Parameters::set_instrumentsMatchScore(int _instrumentsMatchScore)
{
	Parameters::_instrumentsMatchScore = _instrumentsMatchScore;
}

/**
 * documented in header file.
 */
int Parameters::get_bpmLikeMatchScore() const
{
	return _bpmLikeMatchScore;
}

/**
 * documented in header file.
 */
void Parameters::set_bpmLikeMatchScore(int _bpmLikeMatchScore)
{
	Parameters::_bpmLikeMatchScore = _bpmLikeMatchScore;
}

/**
 * documented in header file.
 */
const vector<Mood> &Parameters::get_moods() const
{
	return *_moods;
}

/**
 * documented in header file.
 */
void Parameters::set_moods(vector<Mood> *_moods)
{
	Parameters::_moods = _moods;
}