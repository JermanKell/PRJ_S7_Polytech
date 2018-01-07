#include <exception>
#include "Readfile.h"
#if defined _WIN32 || defined _WIN64
    #include "Command.h"
    #include "gtest\gtest.h"
#elif defined __linux__
    #include "../MatchingLibrary/Command.h"
    #include "gtest/gtest.h"
#endif

TEST(ESC_SystemTest, ESC_character_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\expected_files\\expected_target_character_ref_character_esc_char_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_character_target_character_esc_char_csv\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\target_character.csv",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\ref_character.csv",
			"-method",
			"esc",
			"-parser",
			"csv",
			"-type",
			"character",
			"-param",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\parameters_char_csv.xml",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_character_target_character_esc_char_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

/*TEST(ESC_SystemTest, ESC_numeric_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\expected_files\\expected_target_numeric_ref_numeric_esc_num_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_numeric_target_numeric_esc_num_csv\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\target_numeric.csv",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\ref_numeric.csv",
			"-method",
			"esc",
			"-parser",
			"csv",
			"-type",
			"numeric",
			"-param",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\parameters_num_csv.xml",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_numeric_target_numeric_esc_num_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST(ESC_SystemTest, ESC_vector_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\expected_files\\expected_target_vector_ref_vector_esc_vec_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_vector_target_vector_esc_vec_csv\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\target_vector.csv",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\ref_vector.csv",
			"-method",
			"esc",
			"-parser",
			"csv",
			"-type",
			"vector",
			"-param",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\parameters_vec_csv.xml",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_vector_target_vector_esc_vec_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST(ESC_SystemTest, ESC_character_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\expected_files\\expected_target_character_ref_character_esc_char_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_character_target_character_esc_char_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\target_character.ext",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\ref_character.ext",
			"-method",
			"esc",
			"-parser",
			"ext",
			"-type",
			"character",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_character_target_character_esc_char_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST(ESC_SystemTest, ESC_numeric_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\expected_files\\expected_target_numeric_ref_numeric_esc_num_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_numeric_target_numeric_esc_num_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\target_numeric.ext",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\ref_numeric.ext",
			"-method",
			"esc",
			"-parser",
			"ext",
			"-type",
			"numeric",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_numeric_target_numeric_esc_num_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST(ESC_SystemTest, ESC_vector_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\expected_files\\expected_target_vector_ref_vector_esc_vec_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_vector_target_vector_esc_vec_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\target_vector.ext",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\ref_vector.ext",
			"-method",
			"esc",
			"-parser",
			"ext",
			"-type",
			"vector",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_vector_target_vector_esc_vec_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST(ESC_SystemTest, ESC_character_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\expected_files\\expected_target_character_ref_character_esc_char_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_character_target_character_esc_char_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\target_character.xml",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\ref_character.xml",
			"-method",
			"esc",
			"-parser",
			"xml",
			"-type",
			"character",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_character_target_character_esc_char_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST(ESC_SystemTest, ESC_numeric_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\expected_files\\expected_target_numeric_ref_numeric_esc_num_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_numeric_target_numeric_esc_num_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\target_numeric.xml",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\ref_numeric.xml",
			"-method",
			"esc",
			"-parser",
			"xml",
			"-type",
			"numeric",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_numeric_target_numeric_esc_num_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST(ESC_SystemTest, ESC_vector_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\expected_files\\expected_target_vector_ref_vector_esc_vec_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_vector_target_vector_esc_vec_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\target_vector.xml",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\ref_vector.xml",
			"-method",
			"esc",
			"-parser",
			"xml",
			"-type",
			"vector",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\ESC\\resultat_ref_vector_target_vector_esc_vec_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}*/
