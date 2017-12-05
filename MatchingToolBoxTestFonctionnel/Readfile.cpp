#include "Readfile.h"
#include "SequenceMatchingException.h"
Readfile::Readfile()
{
}

Readfile::Readfile(string name1 , string name2)
{
	filename = name1;
	filename2 = name2;
}
bool Readfile::compareFile()
{
	// la variable compare me dit si le fichier est identique ou pas 
	bool compare = true;
	string rowfile1;
	string rowfile2;




	/* Ce verifie l'existance des fichiers */

	ifstream file1(filename.c_str(), ios::in);
	ifstream file2(filename2.c_str(), ios::in);

	if (file1.fail())
	{
		//throw string("The file 1 : " + filename + " doesn't exist or a problem of reading");
		cerr << "The file 1 : " << filename << " doesn't exist or a problem of reading ! " << endl ;
		return false;
	}
	if (file2.fail())
	{
		//throw string("The file 2 : " + filename + " doesn't exist or a problem of reading");
		cerr << "The file 2 : " << filename2 << " doesn't exist or a problem of reading ! " << endl ;
		return false;
	}

	/*
	Recupere toutes les lignes du fichier 1
	*/
	while (!file1.eof())
	{
		string row = "";
		getline(file1, row);
		rowfile1 += row;
	}
	/*
	Recupere toutes les lignes du fichier 2
	*/
	while (!file2.eof())
	{
		string row = "";
		getline(file2, row);
		rowfile2 += row;
	}
	/*
	On enlève les espaces et les saut lignes 
	*/
	rowfile1 = stringWhithoutCharac(rowfile1, " \n\t\r");
	rowfile2 = stringWhithoutCharac(rowfile2, " \n\t\r");
	if (rowfile1.length() > rowfile2.length() || rowfile1.length() < rowfile2.length())
	{
		compare = false;
	}
	else
	{
		for (unsigned int index = 0; index < rowfile1.length() && compare == true ; index++)
		{
			if (rowfile1[index] != rowfile2[index])
			{
				compare = false;
			}
		}
	}

	return compare ;
}
string Readfile::stringWhithoutCharac(string sequence, string seqCharactere)
{
	string newSequence = "";
	for (unsigned int index = 0; index < sequence.length(); index++)
	{
		if (seqCharactere.find(sequence[index]) == -1)
		{
			newSequence += sequence[index];
		}
	}
	return newSequence;
}
Readfile::~Readfile()
{
}