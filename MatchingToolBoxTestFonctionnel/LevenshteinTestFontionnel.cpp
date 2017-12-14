#include "Readfile.h"
#include <exception>
#include "Command.h"
#include "gtest\gtest.h"

TEST(LevenshteinSystemTest, levenshtein_character_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\expected_files\\expected_target_character_ref_character_lvn_char_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_character_target_character_lvn_char_csv\\1.txt";
	char* args[] = {"MatchingToolBox.exe",
					"-sequences",
					"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\target_character.csv",
					"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\ref_character.csv",
					"-method",
					"lvn",
					"-parser",
					"csv",
					"-type",
					"character",
					"-result",
					"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_character_target_character_lvn_char_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LevenshteinSystemTest, levenshtein_numeric_csv) {

	string expected_file1 = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\expected_files\\expected_target_numeric_ref_numeric_lvn_num_csv_1.txt";
	string expected_file2 = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\expected_files\\expected_target_numeric_ref_numeric_lvn_num_csv_2.txt";
	string result_file1 = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_numeric_target_numeric_lvn_num_csv\\1.txt";
	string result_file2 = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_numeric_target_numeric_lvn_num_csv\\2.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\target_numeric.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\ref_numeric.csv",
		"-method",
		"lvn",
		"-parser",
		"csv",
		"-type",
		"numeric",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_numeric_target_numeric_lvn_num_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);

	ASSERT_NO_THROW(c.run());

	Readfile r1(expected_file1, result_file1);
	Readfile r2(expected_file2, result_file2);

	ASSERT_EQ(r1.compareFile(), true);
	ASSERT_EQ(r2.compareFile(), true);
}

TEST(LevenshteinSystemTest, levenshtein_vector_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\expected_files\\expected_target_vector_ref_vector_lvn_vec_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_vector_target_vector_lvn_vec_csv\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\target_vector.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\ref_vector.csv",
		"-method",
		"lvn",
		"-parser",
		"csv",
		"-type",
		"vector",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_vector_target_vector_lvn_vec_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);

	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LevenshteinSystemTest, levenshtein_character_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\expected_files\\expected_target_character_ref_character_lvn_char_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_character_target_character_lvn_char_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\target_character.ext",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\ref_character.ext",
		"-method",
		"lvn",
		"-parser",
		"ext",
		"-type",
		"character",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_character_target_character_lvn_char_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LevenshteinSystemTest, levenshtein_numeric_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\expected_files\\expected_target_numeric_ref_numeric_lvn_num_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_numeric_target_numeric_lvn_num_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\target_numeric.ext",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\ref_numeric.ext",
		"-method",
		"lvn",
		"-parser",
		"ext",
		"-type",
		"numeric",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_numeric_target_numeric_lvn_num_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LevenshteinSystemTest, levenshtein_vector_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\expected_files\\expected_target_vector_ref_vector_lvn_vec_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_vector_target_vector_lvn_vec_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\target_vector.ext",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\ref_vector.ext",
		"-method",
		"lvn",
		"-parser",
		"ext",
		"-type",
		"vector",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_vector_target_vector_lvn_vec_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LevenshteinSystemTest, levenshtein_character_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\expected_files\\expected_target_character_ref_character_lvn_char_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_character_target_character_lvn_char_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\target_character.xml",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\ref_character.xml",
		"-method",
		"lvn",
		"-parser",
		"xml",
		"-type",
		"character",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_character_target_character_lvn_char_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LevenshteinSystemTest, levenshtein_numeric_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\expected_files\\expected_target_numeric_ref_numeric_lvn_num_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_numeric_target_numeric_lvn_num_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\target_numeric.xml",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\ref_numeric.xml",
		"-method",
		"lvn",
		"-parser",
		"xml",
		"-type",
		"numeric",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_numeric_target_numeric_lvn_num_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LevenshteinSystemTest, levenshtein_vector_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\expected_files\\expected_target_vector_ref_vector_lvn_vec_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_vector_target_vector_lvn_vec_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\target_vector.xml",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\ref_vector.xml",
		"-method",
		"lvn",
		"-parser",
		"xml",
		"-type",
		"vector",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LEVENSHTEIN\\resultat_ref_vector_target_vector_lvn_vec_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}