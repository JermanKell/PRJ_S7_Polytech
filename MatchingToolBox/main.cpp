#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>

#if defined _WIN32 || defined _WIN64
    #include "InOut.h"
    #include "Command.h"
    #include "SequenceMatchingException.h"
#elif defined __linux__
    #include "../MatchingLibrary/InOut.h"
    #include "../MatchingLibrary/Command.h"
    #include "../MatchingLibrary/SequenceMatchingException.h"
#endif

using namespace std;

int main(int argc, char *argv[])
{
	clock_t begin = clock();

	// Uncomment this to test with VS
	/*char* args[] = { "MatchingToolBox.exe", "-sequences",
			"..\\TestingMaterial\\target_character.csv",
			"..\\TestingMaterial\\ref_character.csv",
			"-method", "lvn", "-result" , "..\\TestingMaterial\\results", "-parser", "csv", "-type", "character"
	};
	commandline::CommandLineApplication c(12, args);*/
	//-sequences $(SolutionDir)\TestingMaterial\target_chien.csv $(SolutionDir)\TestingMaterial\ref_niche.csv -method dtw -parser csv -type character

	// Uncomment this to test with CodeBlocks (Linux)
	/*char* args[] = { "MatchingToolBox.exe", "-sequences",
			"../../../VS2015/MatchingToolBox/TestingMaterial/target_character.csv",
			"../../../VS2015/MatchingToolBox/TestingMaterial/ref_character.csv",
			"-method", "lvn", "-result" , "results_linux", "-parser", "csv", "-type", "character"
	};
	commandline::CommandLineApplication c(12, args);*/


	commandline::CommandLineApplication c(argc, argv);

	try {
		c.run();
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
