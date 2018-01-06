#include "Readfile.h"
#include <exception>
#include "Command.h"
#include "gtest\gtest.h"

TEST(MVM_SystemTest, MVM_character_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\expected_files\\expected_target_character_ref_character_mvm_char_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_character_target_character_mvm_char_csv\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\target_character.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\ref_character.csv",
		"-method",
		"mvm",
		"-parser",
		"csv",
		"-type",
		"character",
		"-param",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\parameters_char_csv.xml",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_character_target_character_mvm_char_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);
	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

/*TEST(MVM_SystemTest, MVM_numeric_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\expected_files\\expected_target_numeric_ref_numeric_mvm_num_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_numeric_target_numeric_mvm_num_csv\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\target_numeric.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\ref_numeric.csv",
		"-method",
		"mvm",
		"-parser",
		"csv",
		"-type",
		"numeric",
		"-param",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\parameters_num_csv.xml",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_numeric_target_numeric_mvm_num_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);

	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(MVM_SystemTest, MVM_vector_csv) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\expected_files\\expected_target_vector_ref_vector_mvm_vec_csv.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_vector_target_vector_mvm_vec_csv\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\target_vector.csv",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\ref_vector.csv",
		"-method",
		"mvm",
		"-parser",
		"csv",
		"-type",
		"vector",
		"-param",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\parameters_vec_csv.xml",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_vector_target_vector_mvm_vec_csv" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);

	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(MVM_SystemTest, MVM_character_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\expected_files\\expected_target_character_ref_character_mvm_char_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_character_target_character_mvm_char_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\target_character.ext",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\ref_character.ext",
		"-method",
		"mvm",
		"-parser",
		"ext",
		"-type",
		"character",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_character_target_character_mvm_char_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(MVM_SystemTest, MVM_numeric_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\expected_files\\expected_target_numeric_ref_numeric_mvm_num_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_numeric_target_numeric_mvm_num_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\target_numeric.ext",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\ref_numeric.ext",
		"-method",
		"mvm",
		"-parser",
		"ext",
		"-type",
		"numeric",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_numeric_target_numeric_mvm_num_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(MVM_SystemTest, MVM_vector_ext) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\expected_files\\expected_target_vector_ref_vector_mvm_vec_ext.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_vector_target_vector_mvm_vec_ext\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\target_vector.ext",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\ref_vector.ext",
		"-method",
		"mvm",
		"-parser",
		"ext",
		"-type",
		"vector",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_vector_target_vector_mvm_vec_ext" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(MVM_SystemTest, MVM_character_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\expected_files\\expected_target_character_ref_character_mvm_char_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_character_target_character_mvm_char_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\target_character.xml",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\ref_character.xml",
		"-method",
		"mvm",
		"-parser",
		"xml",
		"-type",
		"character",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_character_target_character_mvm_char_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(MVM_SystemTest, MVM_numeric_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\expected_files\\expected_target_numeric_ref_numeric_mvm_num_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_numeric_target_numeric_mvm_num_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\target_numeric.xml",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\ref_numeric.xml",
		"-method",
		"mvm",
		"-parser",
		"xml",
		"-type",
		"numeric",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_numeric_target_numeric_mvm_num_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST(MVM_SystemTest, MVM_vector_xml) {

	string expected_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\expected_files\\expected_target_vector_ref_vector_mvm_vec_xml.txt";
	string result_file = "..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_vector_target_vector_mvm_vec_xml\\1.txt";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\target_vector.xml",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\ref_vector.xml",
		"-method",
		"mvm",
		"-parser",
		"xml",
		"-type",
		"vector",
		"-result",
		"..\\MatchingToolBoxTestFonctionnel\\TestingMaterial\\MVM\\resultat_ref_vector_target_vector_mvm_vec_xml" };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}*/