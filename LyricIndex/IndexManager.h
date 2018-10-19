/*The index manager will handle all the operation on the index as extractions of ids and insertions ...
it will handle only the index part of the .idly file 
The index part of the file looks like this 
#//separator 
[WORD1]:id1,id2,id3;
[WORD2]:id11,id22,id33;...*/
#include "LyricIndexGlobal.h"
#include "LyricManager.h"
#pragma once


class IndexManager
{
public:
	IndexManager();
	//Initialize Index directely with songs that are in the Lyrics Manager
	IndexManager(LyricManager *resultLyricManager);
	IndexManager(const string loadingFile);
	virtual ~IndexManager();
	//Save changes to the index file
	void CommitChanges(const string exportFile);
	//Add a song to the index by it's id
	songIndex IndexList;
	LyricManager *resultLyricManager;
};