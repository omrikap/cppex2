

#ifndef EX2_INSTRUMANTALSONG_H
#define EX2_INSTRUMANTALSONG_H

#include "Song.h"
using namespace std;

/**
 * @brief The class that represent instrumental songs. Derived from the class Song.
 */
class InstrumentalSong : public Song {
public:

private:
    int calculateScore();

private:
	vector<string> _instruments;
	vector<string> _performedBy;
	vector<string> _mood;
};


#endif //EX2_INSTRUMANTALSONG_H
