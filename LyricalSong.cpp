#include "LyricalSong.h"

int LyricalSong::calculateScore()
{
	return 0;
}

LyricalSong::LyricalSong(vector<string> &title, map<string, int> &tags, vector<string> &lyrics,
                         vector<string> &lyricsBy)
{
	// todo add nullptr test before each setter call
	this->setTitle(title);
	this->setTags(tags);
	this->setLyrics(lyrics);
	this->setLyricsBy(lyricsBy);
}

const vector<string> &LyricalSong::getLyrics() const
{
	return _lyrics;
}

void LyricalSong::setLyrics(const vector<string> &_lyrics)
{
	LyricalSong::_lyrics = _lyrics;
}

const vector<string> &LyricalSong::getLyricsBy() const
{
	return _lyricsBy;
}

void LyricalSong::setLyricsBy(const vector<string> &_lyricsBy)
{
	LyricalSong::_lyricsBy = _lyricsBy;
}