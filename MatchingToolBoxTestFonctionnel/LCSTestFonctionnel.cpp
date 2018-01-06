#include "Readfile.h"
#include <exception>
#include "Command.h"
#include "gtest\gtest.h"

TEST(LCSTest, LCS_character_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\expected_files\\expected_target_ref_character_lcs_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_character_target_character_lcs_char_csv\\1.txt";
	char * args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\target_LCS_character.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\ref_LCS_character.csv",
		"-method",
		"lcs",
		"-parser",
		"csv",
		"-type",
		"character",
		"-param",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\parameters_char_csv.xml",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_character_target_character_lcs_char_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);
	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

/*TEST(LCSTest, LCS_numeric_csv) {

	string expected_file1 = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\expected_files\\expected_target_ref_numeric_lcs_csv1.txt";
	string expected_file2 = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\expected_files\\expected_target_ref_numeric_lcs_csv2.txt";
	string result_file1 = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_numeric_target_numeric_lcs_num_csv\\1.txt";
	string result_file2 = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_numeric_target_numeric_lcs_num_csv\\2.txt";
	char * args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\target_LCS_numeric.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\ref_LCS_numeric.csv",
		"-method",
		"lcs",
		"-parser",
		"csv",
		"-type",
		"numeric",
		"-param",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\parameters_num_csv.xml",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_numeric_target_numeric_lcs_num_csv" };


	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);

	ASSERT_NO_THROW(c.run());

	Readfile r1(expected_file1, result_file1);
	Readfile r2(expected_file2, result_file2);

	ASSERT_EQ(r1.compareFile(), true);
	ASSERT_EQ(r2.compareFile(), true);
}

TEST(LCSTest, lcs_vector_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\expected_files\\expected_target_ref_vector_lcs_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_vector_target_vector_lcs_vec_csv\\1.txt";
	char * args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\target_LCS_vector.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\ref_LCS_vector.csv",
		"-method",
		"lcs",
		"-parser",
		"csv",
		"-type",
		"vector",
		"-param",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\parameters_vec_csv.xml",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_vector_target_vector_lcs_vec_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);
	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LCSTest, LCS_character_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\expected_files\\expected_target_ref_character_lcs_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_character_target_character_lcs_char_ext\\1.txt";
	char * args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\target_LCS_character.ext",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\ref_LCS_character.ext",
		"-method",
		"lcs",
		"-parser",
		"ext",
		"-type",
		"character",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_character_target_character_lcs_char_ext" };
	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LCSTest, LCS_numeric_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\expected_files\\expected_target_ref_numeric_lcs_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_numeric_target_numeric_lcs_num_ext\\1.txt";
	char * args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\target_LCS_numeric.ext",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\ref_LCS_numeric.ext",
		"-method",
		"lcs",
		"-parser",
		"ext",
		"-type",
		"numeric",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_numeric_target_numeric_lcs_num_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LCSTest, LCS_vector_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\expected_files\\expected_target_ref_vector_lcs_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_vector_target_vector_lcs_vec_ext\\1.txt";
	char * args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\target_LCS_vector.ext",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\ref_LCS_vector.ext",
		"-method",
		"lcs",
		"-parser",
		"ext",
		"-type",
		"vector",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_vector_target_vector_lcs_vec_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LCSTest, LCS_character_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\expected_files\\expected_target_ref_character_lcs_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_character_target_character_lcs_char_xml\\1.txt";
	char * args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\target_LCS_character.xml",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\ref_LCS_character.xml",
		"-method",
		"lcs",
		"-parser",
		"xml",
		"-type",
		"character",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_character_target_character_lcs_char_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LCSTest, LCS_numeric_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\expected_files\\expected_target_ref_numeric_lcs_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_numeric_target_numeric_lcs_num_xml\\1.txt";
	char * args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\target_LCS_numeric.xml",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\ref_LCS_numeric.xml",
		"-method",
		"lcs",
		"-parser",
		"xml",
		"-type",
		"numeric",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_numeric_target_numeric_lcs_num_xml" };
	
	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(LCSTest, LCS_vector_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\expected_files\\expected_target_ref_vector_lcs_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_vector_target_vector_lcs_vec_xml\\1.txt";
	char * args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\target_LCS_vector.xml",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\date_file_LCS\\ref_LCS_vector.xml",
		"-method",
		"lcs",
		"-parser",
		"xml",
		"-type",
		"vector",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\LCS\\resultat_ref_vector_target_vector_lcs_vec_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}*/
