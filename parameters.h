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
	// todo constructor
	// todo destructor
	// todo getters/setters

private:
	int _tagMatchScore; /** The weight of tag match */
	int _lyricsMatchScore; /** The weight of lyrics match */
	int _instrumentsMatchScore; /** The weight of instrument match */
	int _bpmLikeMatchScore; /** The weight of mood match */
	vector<Mood> _moods; /** A vector of all available moods */
};


#endif //EX2_PARAMETERS_H
