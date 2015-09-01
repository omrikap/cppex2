

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
	vector<string> _lyrics;
	vector<string> _lyricsBy;
};


#endif //EX2_LYRICALSONG_H
