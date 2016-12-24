#include <stdio.h>
#include "InOut.h"
#include "Command.h"
#include "SequenceMatchingException.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	clock_t begin = clock();
	commandline::CommandLineApplication *c;

	/* // Uncomment this to test 
	char* args[] = { "MatchingToolBox.exe", "-sequences",
			"..\\TestingMaterial\\target.csv",
			"..\\TestingMaterial\\ref.csv",
			"-method", "lvn", "--costs", "1", "1", "1", "-result" , "..\\TestingMaterial"
	};
	c = new commandline::CommandLineApplication(12, args);*/

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

	int test = 0;
	cin >> test;
	return 0;
}
