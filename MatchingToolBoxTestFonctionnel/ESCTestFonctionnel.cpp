#include "ESCTestFonctionnel.h"

TEST_F(ESC_SystemTest, ESC_character_csv) {

	string expected_file = (string)_shared_path_ESC + "expected_files" + _p + "expected_target_character_ref_character_esc_char_csv.txt";
	string result_path = (string)_shared_path_ESC + "resultat_target_character_ref_character_esc_char_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_ESC + "target_character.csv";
	string ref_file = (string)_shared_path_ESC + "ref_character.csv";
	string param_file = (string)_shared_path_ESC + "parameters_char_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"esc",
		"-parser",
		"csv",
		"-type",
		"character",
		"-param",
		&param_file[0u],
		"-result",
		&result_path[0u] };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(ESC_SystemTest, ESC_numeric_csv) {

	string expected_file = (string)_shared_path_ESC + "expected_files" + _p + "expected_target_numeric_ref_numeric_esc_num_csv.txt";
	string result_path = (string)_shared_path_ESC + "resultat_target_numeric_ref_numeric_esc_num_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_ESC + "target_numeric.csv";
	string ref_file = (string)_shared_path_ESC + "ref_numeric.csv";
	string param_file = (string)_shared_path_ESC + "parameters_num_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"esc",
		"-parser",
		"csv",
		"-type",
		"numeric",
		"-param",
		&param_file[0u],
		"-result",
		&result_path[0u] };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(ESC_SystemTest, ESC_vector_csv) {

	string expected_file = (string)_shared_path_ESC + "expected_files" + _p + "expected_target_vector_ref_vector_esc_vec_csv.txt";
	string result_path = (string)_shared_path_ESC + "resultat_target_vector_ref_vector_esc_vec_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_ESC + "target_vector.csv";
	string ref_file = (string)_shared_path_ESC + "ref_vector.csv";
	string param_file = (string)_shared_path_ESC + "parameters_vec_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"esc",
		"-parser",
		"csv",
		"-type",
		"vector",
		"-param",
		&param_file[0u],
		"-result",
		&result_path[0u] };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(ESC_SystemTest, ESC_character_ext) {

	string expected_file = (string)_shared_path_ESC + "expected_files" + _p + "expected_target_character_ref_character_esc_char_ext.txt";
	string result_path = (string)_shared_path_ESC + "resultat_target_character_ref_character_esc_char_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_ESC + "target_character.ext";
	string ref_file = (string)_shared_path_ESC + "ref_character.ext";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"esc",
		"-parser",
		"ext",
		"-type",
		"character",
		"-result",
		&result_path[0u] };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(ESC_SystemTest, ESC_numeric_ext) {

	string expected_file = (string)_shared_path_ESC + "expected_files" + _p + "expected_target_numeric_ref_numeric_esc_num_ext.txt";
	string result_path = (string)_shared_path_ESC + "resultat_target_numeric_ref_numeric_esc_num_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_ESC + "target_numeric.ext";
	string ref_file = (string)_shared_path_ESC + "ref_numeric.ext";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"esc",
		"-parser",
		"ext",
		"-type",
		"numeric",
		"-result",
		&result_path[0u] };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(ESC_SystemTest, ESC_vector_ext) {

	string expected_file = (string)_shared_path_ESC + "expected_files" + _p + "expected_target_vector_ref_vector_esc_vec_ext.txt";
	string result_path = (string)_shared_path_ESC + "resultat_target_vector_ref_vector_esc_vec_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_ESC + "target_vector.ext";
	string ref_file = (string)_shared_path_ESC + "ref_vector.ext";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"esc",
		"-parser",
		"ext",
		"-type",
		"vector",
		"-result",
		&result_path[0u] };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(ESC_SystemTest, ESC_character_xml) {

	string expected_file = (string)_shared_path_ESC + "expected_files" + _p + "expected_target_character_ref_character_esc_char_xml.txt";
	string result_path = (string)_shared_path_ESC + "resultat_target_character_ref_character_esc_char_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_ESC + "target_character.xml";
	string ref_file = (string)_shared_path_ESC + "ref_character.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"esc",
		"-parser",
		"xml",
		"-type",
		"character",
		"-result",
		&result_path[0u] };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(ESC_SystemTest, ESC_numeric_xml) {

	string expected_file = (string)_shared_path_ESC + "expected_files" + _p + "expected_target_numeric_ref_numeric_esc_num_xml.txt";
	string result_path = (string)_shared_path_ESC + "resultat_target_numeric_ref_numeric_esc_num_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_ESC + "target_numeric.xml";
	string ref_file = (string)_shared_path_ESC + "ref_numeric.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"esc",
		"-parser",
		"xml",
		"-type",
		"numeric",
		"-result",
		&result_path[0u] };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(ESC_SystemTest, ESC_vector_xml) {

	string expected_file = (string)_shared_path_ESC + "expected_files" + _p + "expected_target_vector_ref_vector_esc_vec_xml.txt";
	string result_path = (string)_shared_path_ESC + "resultat_target_vector_ref_vector_esc_vec_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_ESC + "target_vector.xml";
	string ref_file = (string)_shared_path_ESC + "ref_vector.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"esc",
		"-parser",
		"xml",
		"-type",
		"vector",
		"-result",
		&result_path[0u] };

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);
	ASSERT_EQ(r.compareFile(), true);
}