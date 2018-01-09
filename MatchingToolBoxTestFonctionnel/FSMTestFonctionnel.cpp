#include <exception>
#include "Readfile.h"
#include "Command.h"
#include "GtestEnvironment.h"

TEST(FSM_SystemTest, FSM_character_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\expected_files\\expected_target_character_ref_character_fsm_char_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_character_target_character_fsm_char_csv\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\target_character.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\ref_character.csv",
		"-method",
		"fsm",
		"-parser",
		"csv",
		"-type",
		"character",
		"-param",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\parameters_char_csv.xml",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_character_target_character_fsm_char_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);
	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

/*TEST(FSM_SystemTest, FSM_numeric_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\expected_files\\expected_target_numeric_ref_numeric_fsm_num_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_numeric_target_numeric_fsm_num_csv\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\target_numeric.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\ref_numeric.csv",
		"-method",
		"fsm",
		"-parser",
		"csv",
		"-type",
		"numeric",
		"-param",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\parameters_num_csv.xml",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_numeric_target_numeric_fsm_num_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);

	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_vector_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\expected_files\\expected_target_vector_ref_vector_fsm_vec_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_vector_target_vector_fsm_vec_csv\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\target_vector.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\ref_vector.csv",
		"-method",
		"fsm",
		"-parser",
		"csv",
		"-type",
		"vector",
		"-param",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\parameters_vec_csv.xml",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_vector_target_vector_fsm_vec_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);

	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_character_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\expected_files\\expected_target_character_ref_character_fsm_char_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_character_target_character_fsm_char_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\target_character.ext",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\ref_character.ext",
		"-method",
		"fsm",
		"-parser",
		"ext",
		"-type",
		"character",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_character_target_character_fsm_char_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_numeric_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\expected_files\\expected_target_numeric_ref_numeric_fsm_num_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_numeric_target_numeric_fsm_num_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\target_numeric.ext",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\ref_numeric.ext",
		"-method",
		"fsm",
		"-parser",
		"ext",
		"-type",
		"numeric",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_numeric_target_numeric_fsm_num_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_vector_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\expected_files\\expected_target_vector_ref_vector_fsm_vec_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_vector_target_vector_fsm_vec_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\target_vector.ext",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\ref_vector.ext",
		"-method",
		"fsm",
		"-parser",
		"ext",
		"-type",
		"vector",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_vector_target_vector_fsm_vec_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_character_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\expected_files\\expected_target_character_ref_character_fsm_char_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_character_target_character_fsm_char_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\target_character.xml",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\ref_character.xml",
		"-method",
		"fsm",
		"-parser",
		"xml",
		"-type",
		"character",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_character_target_character_fsm_char_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_numeric_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\expected_files\\expected_target_numeric_ref_numeric_fsm_num_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_numeric_target_numeric_fsm_num_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\target_numeric.xml",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\ref_numeric.xml",
		"-method",
		"fsm",
		"-parser",
		"xml",
		"-type",
		"numeric",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_numeric_target_numeric_fsm_num_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(FSM_SystemTest, FSM_vector_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\expected_files\\expected_target_vector_ref_vector_fsm_vec_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_vector_target_vector_fsm_vec_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\target_vector.xml",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\ref_vector.xml",
		"-method",
		"fsm",
		"-parser",
		"xml",
		"-type",
		"vector",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\FSM\\resultat_ref_vector_target_vector_fsm_vec_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}*/
