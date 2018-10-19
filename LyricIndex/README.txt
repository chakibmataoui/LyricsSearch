MATAOUI CHAKIB SOULEYMAN LSIMM (Lyrics Search Index Manager Module)
Global description : 
	This module is responsible for the managment of the database used in the serach engine
Functionalities : 
	This module does : 
	-Retrive the lyrics from lyrics files 
	-Convert lyrics to index pointers 
	-Save the db into a file that would be used later (and export the functions for reading that database)
Files structure : 
	-.ly (lyrics) : [Song Title | Song lyrics]\n... 
		The lyrics will be modified over the time the first version will be ascii the others will have extended chars 
	-.idxly (Indexed lyrics) :
	{word,id},{word,id}....
	#
	word[songid,nextwordid][songid,nextwordid];....
