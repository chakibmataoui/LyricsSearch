/*
Mataoui Chakib Souleyman
Char File Comparaison 
A very very simple program i used to compare two files char by char
I tought may be it could be useful to share it to some people who would like to learn some basic c++*/
#include <iostream>
#include <fstream>

using namespace std;
int main(int argc,char** argv){
	if(argc < 2){
		cout << "Too few arguments";
		return -1000;//random exit code used
	}
	
	ifstream file1(argv[1]), file2(argv[2]);
	if(!file1.is_open()){
		cout << "File 1 not found aborting execution";
		return -2000;
	}
	cout << "File 1 opened " << endl;
	if(!file2.is_open()){
		cout << "File 2 not found aborting execution";
		return -2000;
	}
	cout << "File 2 opened " << endl;
	char file1Point,file2Point;//Current file char
	long long pos = 0,diff = 0;
	cout << "Starting comparaison" << endl;
	while(!file1.eof() && !file2.eof()){
		file1 >> file1Point;
		file2 >> file2Point;
		pos++;
		if(file1Point != file2Point){
			diff++;
			cout << "Difference at position " << pos << " for char in file 1 \"" << file1Point << "\" and in file 2 \"" << file2Point << "\"" << endl;
		}
	}
	cout << "Comparaison finished found : " << diff << " chars different in both files " << endl;
	return 0;
}