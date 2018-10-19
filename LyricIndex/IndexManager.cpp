#include "IndexManager.h"


IndexManager::IndexManager() {

}

IndexManager::IndexManager( LyricManager *resultLyricManager)
{
	this->resultLyricManager = resultLyricManager;
	/*the first thing to do is to construct an index dictionary which will contain all the words existing*/
	list<string>::iterator curWord,nextWord;
	string word;
	WordNode wordToadd;
	WordNodeList::iterator multipleCheck;
	for (int i = 0;i < resultLyricManager->Songs.size();i++) {
		curWord = resultLyricManager->Songs[i].lyrics.begin();
		while (curWord != resultLyricManager->Songs[i].lyrics.end()) {
			//If the word doens't exist add it
			if (IndexList.find(*curWord) == IndexList.end()) {
				WordNodeList nodeList;
				IndexList[*curWord] = nodeList;
			}
			//add the word and the next word
		
			wordToadd.song = resultLyricManager->Songs[i].id;
			curWord++;
			if (curWord != resultLyricManager->Songs[i].lyrics.end()) {
				wordToadd.nextWord = *curWord;
			}
			else
				wordToadd.nextWord = "";
			curWord--;
			for (multipleCheck = IndexList[*curWord].begin();multipleCheck != IndexList[*curWord].end();multipleCheck++) {
				if (multipleCheck->first == wordToadd.song && multipleCheck->second == wordToadd.nextWord)
					break;
			}
			if(multipleCheck == IndexList[*curWord].end())
				IndexList[*curWord].insert(pair<SongId, string>(wordToadd.song, wordToadd.nextWord));
			curWord++;
		}
		cout << "Indexing :\t"<< i+1 << "/" << resultLyricManager->Songs.size() << endl;
	}
	cout << "Index Created" << endl;
}


IndexManager::~IndexManager()
{
}

void IndexManager::CommitChanges(const string exportFile) {
	cout << "Exporting index to :" << exportFile << endl;
	ofstream exportF(exportFile);
	songIndex::iterator lol = IndexList.begin();
	wordNodeList::iterator it;
	map<string, int> dictionary;
	/*First part saving the dictionary*/

	/*Seconf part saving the index*/
	while (lol != IndexList.end()) {
		exportF << lol->first;
		it = lol->second.begin();
		while (it != lol->second.end()) {
			exportF << "[" << it->first << "," << it->second << "]";
			it++;
		}
		exportF << ";";
		lol++;
	}
	exportF.close();
	cout << "Index Exported\a" << endl;
}
IndexManager::IndexManager(const string loadingFile) {
	ifstream indexFile(loadingFile);
	if (!indexFile.is_open()) {
		cout << "Couldn't open file" << endl;
		exit(1000);
	}
	cout << "Starting extraction data ..." << endl;
	char getC;
	string Idxword = "",Id = "",nextWord = "";
	int Idcast;
	wordNodeList::iterator multipleCheck;
	cout << "Extraction of data ..." << endl;
	while (!indexFile.eof()) {
		//Get The word first
		while(1) {
			indexFile >> getC;
			if (getC == '[' || indexFile.eof())
				break;
			Idxword += getC;
		} 
		//Get the next word
		while (!indexFile.eof()) {
			//Get the song 
			while (1) {
				indexFile >> getC;
			
				if (getC == ',')
					break;
				Id += getC;
			}
			//get next word
			while (1) {
				indexFile >> getC;
				if (getC == ']')
					break;
				nextWord += getC;
			}
			//add to map here
			for (multipleCheck = IndexList[Idxword].begin(); multipleCheck != IndexList[Idxword].end(); multipleCheck++) {
				if (multipleCheck->first == atoll(Id.c_str()) && multipleCheck->second == nextWord)
					break;
			}
			if (multipleCheck == IndexList[Idxword].end())
				IndexList[Idxword].insert(pair<SongId, string>(atoll(Id.c_str()), nextWord));
			Id = "";
			nextWord = "";
			indexFile >> getC;
			if (getC == ';')
				break;
		}
		Idxword = "";
		
	}
	cout << "Extraction Finished" << endl;
}