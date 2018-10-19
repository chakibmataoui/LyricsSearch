#include "LyricIndexGlobal.h"

#pragma once
/*This is the manager for the LY files which contains lyrics and songs associated with it 
It should create a list of songs and their lyrics buffer that's it it doesn't manage the ids or indexing
LY data file structure
[songname,lyrics]
*/
class LyricManager
{
public:
	LyricManager(const string LyricsFile);
	virtual ~LyricManager();
	void showSongs();
	vector<Song> Songs;
	static SongId globalid;
};

