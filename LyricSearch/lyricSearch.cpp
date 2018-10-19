#include "lyricSearch.h"

request_result searchForSongs(request_sentence *Lyrics, songIndex *idx) {
	request_result finalResult;
	songResult songResultData;
	for (int sentence_it = 0;sentence_it < Lyrics->size();++sentence_it) {

	}
	return request_result(0);
}

request_sentence convertRequestLine(string* requestLine) {
	request_sentence sentence; //An vector of setences with each sentence is a vector of words
	string word;
	sentence.resize(1);
	int i = 0; //Current sentence
			   /*Converting the string to sentence*/
	for (string::iterator it = requestLine->begin();it != requestLine->end(); it++) {
		while (*it != ' ' && *it != ',' && *it != '\n') {
			//copy word
			word += *it;
			it++;
			if (it == requestLine->end())
				break;
		}
		tolowerstring(&word);
		if(word.compare("") != 0)
			sentence[sentence.size() - 1].push_back(word);
		word = "";
		if (it == requestLine->end())
			break;
		if (*it == ',')
			sentence.resize(sentence.size() + 1);
	}
	return sentence;	
	
}

static void tolowerstring(string *word) {
	for (int i = 0;i < word->length();++i) {
		word->at(i) = tolower( word->at(i));
	}
}