

#ifndef EX2_INSTRUMANTALSONG_H
#define EX2_INSTRUMANTALSONG_H

#include "Song.h"
using namespace std;

/**
 * @brief The class that represent instrumental songs. Derived from the class Song.
 */
class InstrumantalSong : public Song {
public:

private:
    int calculateScore();

private:
	vector _instruments;
	vector _performedBy;
	vector _mood;
};


#endif //EX2_INSTRUMANTALSONG_H
