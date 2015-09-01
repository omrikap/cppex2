#include "Song.h"


/*
 * documented in the header file
 */
int Song::calculateScore()
{
	return 0;
}

/*
 * documented in the header file
 */
int Song::getScore() const
{
	return _score;
}

/*
 * documented in the header file
 */
void Song::setScore(int _score)
{
	Song::_score = _score;
}

/*
 * documented in the header file
 */
const string &Song::getTitle() const
{
	return _title;
}

/*
 * documented in the header file
 */
void Song::setTitle(const string &title)
{
	Song::_title = title;
}

/*
 * documented in the header file
 */
const map<string, int> &Song::getTags() const
{
	return _tags;
}

/*
 * documented in the header file
 */
void Song::setTags(const map<string, int> &_tags)
{
	Song::_tags = _tags;
}