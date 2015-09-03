#include "LyricalSong.h"

int LyricalSong::calculateScore(string &query, Parameters parameters)
{
	int tagScore = 0;
	int lyricSong = 0;

	if (_tags[query])
	{
		tagScore = _tags[query] * parameters.get_tagMatchScore();
	}

	if (find(_lyrics.begin(), _lyrics.end(), query) != _lyrics.end())
	{
		lyricSong = parameters.get_lyricsMatchScore();
	}

	_score = tagScore + lyricSong;
	return 0;
}

LyricalSong::LyricalSong(vector<string> &title, map<string, int> &tags, vector<string> &lyrics,
                         vector<string> &lyricsBy)
{
	// todo add nullptr test before each setter call
	_title = title;
	_tags = tags;
	_lyrics = lyrics;
	_lyricsBy = lyricsBy;
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