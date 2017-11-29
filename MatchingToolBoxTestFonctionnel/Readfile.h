#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
* Cette classe permet la lecteure de deux fichiers et de les comparer 
*/
class Readfile
{
public:
	Readfile();
	Readfile(string name1 , string name2);
	/*
		Cette methode permet de lire les deux fichiers et dire si elle sont égale 
	*/
	bool compareFile();

	~Readfile();

private:
	/* Le nom du 1er fichier */
	string filename;
	/*le nom du 2 eme fichier */
	string filename2;

	string stringWhithoutCharac(string sequence, string seqCharactere);

};



