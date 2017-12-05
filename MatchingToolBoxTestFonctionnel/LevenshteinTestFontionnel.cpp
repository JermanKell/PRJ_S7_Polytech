#include "Readfile.h"
#include <exception>
#include "Command.h"
#include "gtest\gtest.h"

TEST(LevenshteinSystemTest, levenshtein_character_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\expected_files\\expected_target_character_ref_character.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\resultatref_character_target_character\\1.txt";
	char* args[] = {"MatchingToolBox.exe",
					"-sequences",
					"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\target_character.csv",
					"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ref_character.csv",
					"-method",
					"lvn",
					"-type",
					"character",
					"-result",
					"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\resultatref_character_target_character" };

	commandline::CommandLineApplication c =  commandline::CommandLineApplication(10, args);

	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

/*TEST(LevenshteinSystemTest, levenshtein_numeric_csv) {
	commandline::CommandLineApplication *c;

	string expected_file1 = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\expected_files\\expected_target_numeric_ref_numeric_1.txt";
	string expected_file2 = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\expected_files\\expected_target_numeric_ref_numeric_2.txt";
	string result_file1 = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\resultatref_numeric_target_numeric\\1.txt";
	string result_file2 = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\resultatref_numeric_target_numeric\\2.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\target_numeric.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ref_numeric.csv",
		"-method",
		"lvn",
		"-type",
		"numeric",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\resultatref_numeric_target_numeric" };

	c = new commandline::CommandLineApplication(10, args);

	ASSERT_NO_THROW(c->run());

	Readfile r1(expected_file1, result_file1);
	Readfile r2(expected_file2, result_file2);

	ASSERT_EQ(r1.compareFile(), true);
	ASSERT_EQ(r2.compareFile(), true);
}

TEST(LevenshteinSystemTest, levenshtein_vector_csv) {
	commandline::CommandLineApplication *c;

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\expected_files\\expected_target_vector_ref_vector.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\resultatref_vector_target_vector\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\target_vector.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ref_vector.csv",
		"-method",
		"lvn",
		"-type",
		"vector",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\resultatref_vector_target_vector" };

	c = new commandline::CommandLineApplication(10, args);

	ASSERT_NO_THROW(c->run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}
//////////////////////////////////////////////////////////
TEST(LevenshteinSystemTest, levenshtein_character_ext) {

	string expected_file = "TestingMaterial\\expected_files\\expected_target_character_ref_character.txt";
	string result_file = "TestingMaterial\\resultatref_character_target_character\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\target_character.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ref_character.csv",
		"-method",
		"lvn",
		"-type",
		"character", };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(8, args);

	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LevenshteinSystemTest, levenshtein_numeric_ext) {
}

TEST(LevenshteinSystemTest, levenshtein_vector_ext) {
}*/