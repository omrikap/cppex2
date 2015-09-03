// Mood.h

#ifndef EX2_MOOD_H
#define EX2_MOOD_H

#include <iostream>

class Mood
{
public:
    void setName(const std::string &name);

    void setAverage(float average);

    void setDeviation(float deviation);

    const std::string & getName() const;

    float getAverage() const;

    float getDeviation() const;

private:
	std::string _name;
    float _average;
    float _deviation;
};


#endif //EX2_MOOD_H
