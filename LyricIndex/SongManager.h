/*This manager is set to handle the song search only*/
#include "LyricIndexGlobal.h"
#include "LyricManager.h"
#pragma once
class SongManager
{
public:
	SongManager(const string FileIndex);
	virtual ~SongManager();
	map<SongId, string> SongsList;
private:
	string FileIndex;
};

