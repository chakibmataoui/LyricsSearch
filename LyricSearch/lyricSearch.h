#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../LyricIndex/IndexManager.h"

using namespace std;
typedef struct songResult { string songName;double percent; } songResult;
typedef vector<vector<string>> request_sentence;
typedef vector<songResult> request_result;

/*Used to convert a string to a vector of sentence of words*/
request_sentence convertRequestLine(string *requestLine);

request_result searchForSongs(request_sentence *Lyrics, songIndex *idx);

static void tolowerstring(string *word);
