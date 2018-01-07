#include <exception>
#include "Readfile.h"
#if defined _WIN32 || defined _WIN64
    #include "Command.h"
    #include "gtest\gtest.h"
#elif defined __linux__
    #include "../MatchingLibrary/Command.h"
    #include "gtest/gtest.h"
#endif

TEST(CDP_SystemTest, CDP_character_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\expected_files\\expected_target_character_ref_character_cdp_char_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_character_target_character_cdp_char_csv\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\target_character.csv",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\ref_character.csv",
			"-method",
			"cdp",
			"-parser",
			"csv",
			"-type",
			"character",
			"-param",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\parameters_char_csv.xml",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_character_target_character_cdp_char_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);
	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

/*TEST(FSM_SystemTest, FSM_numeric_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\expected_files\\expected_target_numeric_ref_numeric_cdp_num_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_numeric_target_numeric_cdp_num_csv\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\target_numeric.csv",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\ref_numeric.csv",
			"-method",
			"cdp",
			"-parser",
			"csv",
			"-type",
			"numeric",
			"-param",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\parameters_num_csv.xml",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_numeric_target_numeric_cdp_num_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);

	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_vector_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\expected_files\\expected_target_vector_ref_vector_cdp_vec_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_vector_target_vector_cdp_vec_csv\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\target_vector.csv",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\ref_vector.csv",
			"-method",
			"cdp",
			"-parser",
			"csv",
			"-type",
			"vector",
			"-param",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\parameters_vec_csv.xml",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_vector_target_vector_cdp_vec_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);

	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_character_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\expected_files\\expected_target_character_ref_character_cdp_char_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_character_target_character_cdp_char_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\target_character.ext",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\ref_character.ext",
			"-method",
			"cdp",
			"-parser",
			"ext",
			"-type",
			"character",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_character_target_character_cdp_char_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_numeric_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\expected_files\\expected_target_numeric_ref_numeric_cdp_num_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_numeric_target_numeric_cdp_num_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\target_numeric.ext",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\ref_numeric.ext",
			"-method",
			"cdp",
			"-parser",
			"ext",
			"-type",
			"numeric",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_numeric_target_numeric_cdp_num_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_vector_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\expected_files\\expected_target_vector_ref_vector_cdp_vec_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_vector_target_vector_cdp_vec_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\target_vector.ext",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\ref_vector.ext",
			"-method",
			"cdp",
			"-parser",
			"ext",
			"-type",
			"vector",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_vector_target_vector_cdp_vec_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_character_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\expected_files\\expected_target_character_ref_character_cdp_char_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_character_target_character_cdp_char_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\target_character.xml",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\ref_character.xml",
			"-method",
			"cdp",
			"-parser",
			"xml",
			"-type",
			"character",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_character_target_character_cdp_char_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_numeric_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\expected_files\\expected_target_numeric_ref_numeric_cdp_num_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_numeric_target_numeric_cdp_num_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\target_numeric.xml",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\ref_numeric.xml",
			"-method",
			"cdp",
			"-parser",
			"xml",
			"-type",
			"numeric",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_numeric_target_numeric_cdp_num_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_vector_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\expected_files\\expected_target_vector_ref_vector_cdp_vec_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_vector_target_vector_cdp_vec_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\target_vector.xml",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\ref_vector.xml",
			"-method",
			"cdp",
			"-parser",
			"xml",
			"-type",
			"vector",
			"-result",
			"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\CDP\\resultat_ref_vector_target_vector_cdp_vec_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}*/
