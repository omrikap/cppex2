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



protected:
	/**
	 *
	 */
	int _score;

	/**
	 *
	 */
    vector _title;

	/**
	 *
	 */
    map<string ,int> _tags;
};


#endif //EX2_SONG_H
