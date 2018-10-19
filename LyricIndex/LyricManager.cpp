#include "LyricManager.h"



LyricManager::LyricManager(const string LyricsFile)
{
	int advancement = 0,advpercentage = 0;
	streampos fileSize;
	ifstream LyrRessFile(LyricsFile, ifstream::in);
	if (!LyrRessFile.is_open()) {
		cout << "Couldn't open LyricsRessourceFile" << endl;
		exit(1000);
	}
	//Calculate File Size to know advancement
	LyrRessFile.seekg(0,LyrRessFile.end);
	fileSize = LyrRessFile.tellg();
	LyrRessFile.seekg(0,LyrRessFile.beg);
	//GetFile
	char getC;
	Song addSong;
	string LyricWord;
	while (!LyrRessFile.eof()) {
		addSong.song = "";
		addSong.lyrics.clear();
		
		LyrRessFile.read(&getC, 1);
		advancement++;
		if (getC == '[') {
			globalid++;
			addSong.id = globalid;
			//Read the title 
			LyrRessFile.read(&getC, 1);
			advancement++;
			while(getC != '|') {
				addSong.song += getC;
				LyrRessFile.read(&getC, 1);
				advancement++;
			}
			LyrRessFile.read(&getC, 1);
			advancement++;
			while (getC != ']') {
				LyricWord = "";
				while (getC == ' ') {
					LyrRessFile.read(&getC, 1);
					advancement++;
				}
				while (getC != ' ')
				{
					LyricWord += getC;
					LyrRessFile.read(&getC, 1);
					advancement++;
				}

				if (!regex_match(LyricWord,regex("(x)([0-9]*)"))) {
					addSong.lyrics.push_back(LyricWord);
					LyrRessFile.read(&getC, 1);
					advancement++;
				}
			}
			Songs.push_back(addSong);
			advpercentage = (advancement*100 / fileSize);
			cout << "Extraction : " << advpercentage << "%" << endl;
		}
	}
	cout << "Extraction of lyrics finished" << endl;
}

LyricManager::~LyricManager()
{
}

void LyricManager::showSongs() {
	vector<Song>::iterator it = Songs.begin();
	while (it != Songs.end()) {
		list<string>::iterator Lyrword = it->lyrics.begin();
		cout << it->id << " " << " " << it->song << endl;
		while (Lyrword != it->lyrics.end()) {
			cout << Lyrword->c_str() << '\t';
			++Lyrword;
		}
		cout << endl;
		++it;
	}
}

SongId LyricManager::globalid = 0;