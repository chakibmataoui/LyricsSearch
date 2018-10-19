/*I need to create an index for words in song's lyrics
The file should be structured as : 
	-Lyric Ids	(Lyric manager)
	-Words and the ids they refer to (Index manager)
The file's extension should be .idly
NOTE : this functions with english songs only for now i'll try to extend this to more languages later
*/
#include <iostream>
#include <string>
#include <regex>
#include <list>
#include "LyricManager.h"
#include "IndexManager.h"
using namespace std;



int main(int argc, char **argv) {
	/*LyricIndex "Name of file.ly" 
	NOTE : .ly file syntax = Name of song = Lyrics (unicode at max formated) ;*/
	//LyricManager ly("exportedLyrics.ly");
	//ly.showSongs();
	//IndexManager idx(&ly);
	IndexManager idx("AutomationFile.idxly");
	idx.CommitChanges("AutmationCompare.idxly");
	//idx.CommitChanges("AutomationFile.idxly");
	
	//ly.showSongs();
	/*if (argc > 2) {
		
	}
	else
		cerr << "Missing file names  : " << endl << "LyricIndex $1 $2" << endl << "$1 : list of songs and lyrics\n$2 : Index file to save";
	return 0;*/
}