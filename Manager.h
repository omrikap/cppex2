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
 * @brief
 */
class Manager
{
public:
	/**
	 * @brief
	 */
    std::string getWordList(const std::string line);

	/**
	 * @brief
	 */
	list<Song>* readSongsFromFile(std::string songsFileName);

private:
	/** @brief The list of songs */
	list<Song> _theSongs;
};

#endif //EX2_READINGSONGSTEMPLATE_H
