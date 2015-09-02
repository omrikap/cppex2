#include "InstrumentalSong.h"

int InstrumentalSong::calculateScore()
{
	cout << this->_score; //todo remove
	return Song::calculateScore();
}
