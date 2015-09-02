// LyricalSong.h

#ifndef EX2_LYRICALSONG_H
#define EX2_LYRICALSONG_H

#include "Song.h"

/**
 * @brief This class represents a song with lyrics.
 */
class LyricalSong : public Song {

public:
// --------------------------------- constructors -------------------------------------------------
	/**
	 * @brief the default constructor.
	 */
    LyricalSong(); //todo remove?

	/**
	 * @brief A constructor for the parsing process. Used by the manager.
	 * @param todo
	 * @param todo
	 */
	LyricalSong(string &title); //todo finish constructor signature.

// -------------------------------------- methods -------------------------------------------------
	int calculateScore();

private:

// --------------------------------- data-members -------------------------------------------------
	vector<string> _lyrics;
	vector<string> _lyricsBy;
};


#endif //EX2_LYRICALSONG_H
