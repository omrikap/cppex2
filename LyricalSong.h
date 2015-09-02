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
//    LyricalSong(); //todo remove?

	/**
	 * @brief A constructor for the parsing process. Used by the manager.
	 * @param todo
	 * @param todo
	 */
	LyricalSong(vector<string> &title, map<string, int> &tags, vector<string> &lyrics,
	            vector<string> &lyricsBy);

// -------------------------------------- methods -------------------------------------------------
	/**
	 * @brief todo
	 */
    int calculateScore();

	/**
	 * @brief lyrics getter.
	 */
    const vector<string> &getLyrics() const;

    /**
	 * @brief lyrics setter.
	 */
    void setLyrics(const vector<string> &_lyrics);

    /**
	 * @brief lyricsBy getter.
	 */
    const vector<string> &getLyricsBy() const;

    /**
	 * @brief lyricsBy setter.
	 */
    void setLyricsBy(const vector<string> &_lyricsBy);

private:

// --------------------------------- data-members -------------------------------------------------
	vector<string> _lyrics; /** The lyrics of the song */
	vector<string> _lyricsBy; /** The writer of the song */
};


#endif //EX2_LYRICALSONG_H
