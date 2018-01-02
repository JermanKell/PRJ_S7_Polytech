#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>

#include "InOut.h"
#include "Command.h"
#include "SequenceMatchingException.h"

using namespace std;

int main(int argc, char *argv[])
{
	clock_t begin = clock();
	commandline::CommandLineApplication *c;

	// Uncomment this to test *
	/*char* args[] = { "MatchingToolBox.exe", "-sequences",
			"..\\TestingMaterial\\target_character.csv",
			"..\\TestingMaterial\\ref_character.csv",
			"-method", "lvn", "-result" , "..\\TestingMaterial\\results", "-parser", "csv", "-type", "character"
	};
	c = new commandline::CommandLineApplication(12, args);*/
	//-sequences $(SolutionDir)\TestingMaterial\target_chien.csv $(SolutionDir)\TestingMaterial\ref_niche.csv -method dtw -parser csv -type character
	c = new commandline::CommandLineApplication(argc, argv);

	try {
		c->run();
	} catch (exc::SequenceMatchingException & e) {
		std::cout << e.what() << std::endl;
		std::cout << "Use --help" << std::endl;
	}


	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Matching sequences took : " << elapsed_secs << " seconds" << endl;
	
	getchar();
	return 0;
}
