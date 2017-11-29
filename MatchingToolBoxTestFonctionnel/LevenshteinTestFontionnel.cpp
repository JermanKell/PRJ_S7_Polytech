#include "Readfile.h"
#include "SequenceMatchingException.h"
#include "Command.h"
#include "gtest\gtest.h"

TEST(LevenshteinSystemTest, levenshtein_character_csv) {

	string expected_file = "TestingMaterial\\expected_files\\expected_target_chien_ref_niche.txt";
	string result_file = "TestingMaterial\\resultatref_niche_target_chien\\1.txt";
	char* args[] = {"MatchingToolBox.exe",
					"-sequences",
					"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\target_chien.csv",
					"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ref_niche.csv",
					"-method",
					"lvn",
					"-type",
					"character"};

	commandline::CommandLineApplication c =  commandline::CommandLineApplication(8, args);

	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LevenshteinSystemTest, levenshtein_numeric_csv) {
	commandline::CommandLineApplication *c;

	string expected_file1 = "TestingMaterial\\expected_files\\expected_target_numeric_ref_numeric1.txt";
	string expected_file2 = "TestingMaterial\\expected_files\\expected_target_numeric_ref_numeric2.txt";
	string result_file1 = "TestingMaterial\\resultatref_numeric_target_numeric\\1.txt";
	string result_file2 = "TestingMaterial\\resultatref_numeric_target_numeric\\2.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\target_numeric.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ref_numeric.csv",
		"-method",
		"lvn",
		"-type",
		"numeric" };

	c = new commandline::CommandLineApplication(8, args);

	ASSERT_NO_THROW(c->run());

	Readfile r1(expected_file1, result_file1);
	Readfile r2(expected_file2, result_file2);

	ASSERT_EQ(r1.compareFile(), true);
	ASSERT_EQ(r2.compareFile(), true);
}

TEST(LevenshteinSystemTest, levenshtein_vector_csv) {

}