// parameters.h

#ifndef EX2_PARAMETERS_H
#define EX2_PARAMETERS_H

#include <iostream>
#include <vector>
#include "Mood.h"

using namespace std;

class Parameters
{
public:
	/**
	 * @brief The default constructor.
	 */
	Parameters();

	/**
	 * @brief The Parameters object destructor.
	 */
	~Parameters();

    /**
     * @brief todo
     */
    int get_tagMatchScore() const;

    /**
     * @brief todo
     */
    void set_tagMatchScore(int _tagMatchScore);

    /**
     * @brief todo
     */
    int get_lyricsMatchScore() const;

    /**
     * @brief todo
     */
    void set_lyricsMatchScore(int _lyricsMatchScore);

    /**
	 * @brief todo
	 */
    int get_instrumentsMatchScore() const;

    /**
	 * @brief todo
	 */
    void set_instrumentsMatchScore(int _instrumentsMatchScore);

    /**
	 * @brief todo
	 */
    int get_bpmLikeMatchScore() const;

    /**
	 * @brief todo
	 */
    void set_bpmLikeMatchScore(int _bpmLikeMatchScore);

    /**
	 * @brief todo
	 */
    const vector<Mood> & get_moods() const;

    void set_moods(vector<Mood> *_moods);

private:
	int _tagMatchScore; /** The weight of tag match */
	int _lyricsMatchScore; /** The weight of lyrics match */
	int _instrumentsMatchScore; /** The weight of instrument match */
	int _bpmLikeMatchScore; /** The weight of mood match */
	vector<Mood> * _moods; /** A vector of all available moods */
};


#endif //EX2_PARAMETERS_H
