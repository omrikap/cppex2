// InstrumentalSong.h

#ifndef EX2_INSTRUMANTALSONG_H
#define EX2_INSTRUMANTALSONG_H

#include "Song.h"
#include "math.h"

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
    vector<string> &performedBy, map<string, int> &mood);

    InstrumentalSong(vector<string> &title, map<string, int> &tags, vector<string> &instruments,
                         vector<string> &performedBy);

    /**
     * @brief This method overrides the calculateScore method of the base class Song.
     */
    virtual void calculateScore(string &query, Parameters parameters) override;

private:
	vector<string> _instruments; /** A vector containing the instruments in the song. */
	vector<string> _performedBy; /** A vector containing performers of the song. */
	map<string, int> _mood; /** A map containing the moods of the song and their weights. */
	string _strBpm; /** A string representation of the song's bpm */
};


#endif //EX2_INSTRUMANTALSONG_H
