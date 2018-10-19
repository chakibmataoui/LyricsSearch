/*For the first version of the software we will assume that the user will give the exact words 0.0.1 MK Alpha Build*/
/*
How Queries work :
-The program checks the request file pool which is appended for each new request and cleaned after that (there's another program that does that and CGI program that 
adds the requests)
-Each request is of this form [requestID,String of words]
For Each Request : 
Do the search and create a string stream which will contain the result than create a file with the requestID and write the string to the file than CLOSE it(very important
because the CGI program will check the file and destroy it after it has been used)
And delete from the pool the request line 

MK 0.0.1 Search with perfect match
MK 0.0.2 Search with probable match
MK 0.0.3 Replace with phonetics
*/

#include "lyricSearch.h"




using namespace std;
int main() {
	/*
	//first open the database 
	IndexManager idx("AutomationFile.idxly");
	//Main loop
	fstream requestPool("");//
	ofstream queryResult;//Will open a file to write the result on it
	/*In this loop we will each time check the query pool file and take the */
	
	/*Independent test --------------------*/
	IndexManager idx("AutomationFile.idxly");
	string requestLine;
	requestLine.resize(256);
	/*Request Line :
	sentence1,sentence2...
	each sentence contains words 
	the fusion between the result of each sentnce is the returned result*/
	std::cout << "Enter request (lyrics 1 , lyrics 2 ... of the same song): ";
	getline(cin, requestLine);
	std::cout << "\n";
	vector<vector<string>> sentence = convertRequestLine(&requestLine);
	cin  >> requestLine;
	return 0;
}

