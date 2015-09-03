// song.h

#include <iostream>
#include <vector>
#include <map>

#ifndef EX2_SONG_H
#define EX2_SONG_H

using namespace std;

/**
 * @brief The Song class. The base class for all song objects.
 */
class Song {
public:
// -------------------------------------- methods -------------------------------------------------

    /**
	 * @brief this method calculates the score of every Song object.
	 */
    virtual int calculateScore();

// --------------------------------- getters and setters ------------------------------------------
    /**
	 * @brief get the score of the current Song object.
	 */
    int getScore(string &query) const;

    /**
	 * @brief set the score of the current Song object.
	 */
    void setScore(int _score);

    /**
     * @brief get the title of the current Song object.
     */
    const vector<string> & getTitle() const;

    /**
	 * @brief set the title of the current Song object.
	 */
    void setTitle(const vector<string> &title);

    /**
     * @brief get the tags of the current Song object.
     */
    const map<string, int> &getTags() const;

    /**
	 * @brief set the tags of the current Song object.
	 */
    void setTags(const map<string, int> &_tags);

protected:
// --------------------------------- data-members -------------------------------------------------

	int _score; /** The score of the song object */
    vector<string> _title; /** The title of the song object */
    map<string ,int> _tags; /** The tags of the song object */
};


#endif //EX2_SONG_H
