

#ifndef EX2_INSTRUMANTALSONG_H
#define EX2_INSTRUMANTALSONG_H

#include "Song.h"
using namespace std;

/**
 * @brief The class that represent instrumental songs. Derived from the class Song.
 */
class InstrumentalSong : public Song {
public:

	/**
	 * @brief A constructor to be used by the manager.
	 */
    InstrumentalSong(vector<string> &title, map<string, int> &tags, vector<string> &instruments,
    vector<string> &performedBy, map<string, double> &mood);

	/**
	 * @brief This method overrides the calculateScore method of the base class Song.
	 */
    int calculateScore() override;

	/**
	 * @brief
	 */
    const vector<string> &getInstruments() const;

    void setInstruments(const vector<string> &_instruments);

    const vector<string> &getPerformedBy() const;

    void setPerformedBy(const vector<string> &_performedBy);


    map<string, double> * getMood() const;

    void setMood(map<string, double> *mood);

private:
	vector<string> _instruments; /** A vector containing the instruments in the song. */
	vector<string> _performedBy; /** A vector containing performers of the song. */
	map<string, double> *_mood; /** A map containing the moods of the song and their weights. */
};


#endif //EX2_INSTRUMANTALSONG_H
