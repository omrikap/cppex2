//
// Created by omri on 9/2/15.
//

#include "Mood.h"

void Mood::setName(const std::string &name)
{
	Mood::_name = name;
}

void Mood::setAverage(float average)
{
	Mood::_average = average;
}

void Mood::setDeviation(float deviation)
{
	Mood::_deviation = deviation;
}

float Mood::getDeviation() const
{
	return _deviation;
}

float Mood::getAverage() const
{
	return _average;
}

const std::string &Mood::getName() const
{
	return _name;
}