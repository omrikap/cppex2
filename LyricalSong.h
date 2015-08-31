

#ifndef EX2_LYRICALSONG_H
#define EX2_LYRICALSONG_H

#include "Song.h"

/**
 * @brief
 */
class LyricalSong : public Song {
public:
	int calculateScore();
private:
	vector _lyrics;
	vector _lyricsBy;
};


#endif //EX2_LYRICALSONG_H
