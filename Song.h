#include <iostream>
#include <vector>
#include <map>

#ifndef EX2_SONG_H
#define EX2_SONG_H

using namespace std;

/**
 * @brief
 */
class Song {
public:
    /**
     * @brief this method calculates the score of every Song object.
     */
    virtual int calculateScore();
    /**
	 * @brief get the score of the current Song object.
	 */
    int getScore() const;

    /**
	 * @brief set the score of the current Song object.
	 */
    void setScore(int _score);

    /**
     * @brief get the title of the current Song object.
     */
    const string & getTitle() const;

    /**
	 * @brief set the title of the current Song object.
	 */
    void setTitle(const string &title);

    /**
     * @brief get the tags of the current Song object.
     */
    const map<string, int> &getTags() const;

    /**
	 * @brief set the tags of the current Song object.
	 */
    void setTags(const map<string, int> &_tags);

protected:
	/**
	 *
	 */
	int _score;

	/**
	 *
	 */
    string _title;

	/**
	 *
	 */
    map<string ,int> _tags;
};


#endif //EX2_SONG_H
