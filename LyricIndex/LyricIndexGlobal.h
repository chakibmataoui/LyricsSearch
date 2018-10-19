#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <iterator>
#include <regex>
extern "C" {
#include <stdio.h>
}
using namespace std;

/*NOTE : TO MODIFY LATER WITH A MORE ADVANCED STRUCTURED IDENTIFICATION*/
typedef uint64_t SongId;
typedef uint64_t WordId;
/*A node of a word and the next word that goes next*/
typedef struct { SongId song; WordId nextWord; } WordNode;
/*Array of word node*/
typedef vector<WordNode> WordNodeList;
/*A map for indexed word and the list of nodes that points to the next word*/
typedef map<WordId, WordNodeList> songIndex;
/*Index for words*/
typedef map<WordId, string> indexDictionary;


//A structure for a list of songs ids that  contains the word defined in that structure
typedef struct WordIndex {
	string Word;
	list<SongId> ListOfSongs;
	WordIndex(string word) :Word(word) {};
	void addSong(SongId id) {
		ListOfSongs.push_back(id);
	}
} WordIndex,*WordIndexPtr;
typedef struct { string song; list<string> lyrics; SongId id; } Song;
