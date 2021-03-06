// Manager.h

#ifndef EX2_READINGSONGSTEMPLATE_H
#define EX2_READINGSONGSTEMPLATE_H

#include <string>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include "Song.h"
#include "parameters.h"

const std::string SEPARATOR = "=";
const std::string END_OF_SONGS = "***";
const std::string TITLE = "title";
const std::string TAGS = "tags";
const std::string LYRICS = "lyrics";
const std::string LYRICS_BY = "lyricsBy";
const std::string INSTRUMENTS = "instruments";
const std::string PERFORMED_BY = "performedBy";
const std::string BPM = "bpm";


/**
 * @brief This class will have the object that manages the general process. fixme
 */
class Manager
{
public:

	/**
	 * todo
	 */
    Manager(); // todo new songList and parameters

	/**
	 * todo
	 */
    ~Manager(); // todo delete songList and parameters

	/**
	 * @brief return all the line between {}
	 * @param line A string containing the current line of the file,
	 * @return A string containing only the words between brackets in the given line.
	 */
    string getWordList(const string line);

	/**
	 * @brief todo
	 */
	list<Song*> * readSongsFromFile(std::string songsFileName);

	/**
	 * @brief todo
	 */
    void readParametersFromFile(string parametersFileName);

private:

// --------------------------------- data-members -------------------------------------------------
	list<Song*> *_theSongs; /** @brief The list of songs */
	Parameters * _parameters;

// -------------------------------------- methods -------------------------------------------------
	/**
	 * @brief bpm to mood.
	 * @param bpm A string with the bpm value of the song.
	 * @return A map which contains the moods of the song and their scores.
	 */
	map<string, int> & bpmToMood(string &bpm);

    /**
	 * @brief A function that convert a string to a vector of strings.
	 * @param theString A reference to the string that we want to convert to a vector.
	 * @return A vector of strings.
	 */
    vector<string> & stringToVector(const string &theString);

    /**
	 * @brief A function that convert a string to a map of strings and ints.
	 * @param theString A reference to the string that we want to convert to a map.
	 * @return A map of strings and ints.
	 */
    map<string, int> & stringToMap(const string &theString);

public:
	void giveScores();
};

#endif //EX2_READINGSONGSTEMPLATE_H
