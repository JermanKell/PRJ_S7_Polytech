#include "LCSTestFonctionnel.h"

TEST_F(LCS_SystemTest, LCS_character_csv) {

	string expected_file = (string)_shared_path_LCS + "expected_files" + _p + "expected_target_character_ref_character_lcs_char_csv.txt";
	string result_path = (string)_shared_path_LCS + "resultat_target_character_ref_character_lcs_char_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LCS + "target_character.csv";
	string ref_file = (string)_shared_path_LCS + "ref_character.csv";
	string param_file = (string)_shared_path_LCS + "parameters_char_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lcs",
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

TEST_F(LCS_SystemTest, LCS_numeric_csv) {

	string expected_file1 = (string)_shared_path_LCS + "expected_files" + _p + "expected_target_numeric_ref_numeric_lcs_num_csv_1.txt";
	string expected_file2 = (string)_shared_path_LCS + "expected_files" + _p + "expected_target_numeric_ref_numeric_lcs_num_csv_2.txt";
	string result_path = (string)_shared_path_LCS + "resultat_target_numeric_ref_numeric_lcs_num_csv";
	string result_file1 = result_path + _p + "1.txt";
	string result_file2 = result_path + _p + "2.txt";
	string target_file = (string)_shared_path_LCS + "target_numeric.csv";
	string ref_file = (string)_shared_path_LCS + "ref_numeric.csv";
	string param_file = (string)_shared_path_LCS + "parameters_num_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lcs",
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

	Readfile r1(expected_file1, result_file1);
	Readfile r2(expected_file2, result_file2);

	ASSERT_EQ(r1.compareFile(), true);
	ASSERT_EQ(r2.compareFile(), true);
}

TEST_F(LCS_SystemTest, lcs_vector_csv) {

	string expected_file = (string)_shared_path_LCS + "expected_files" + _p + "expected_target_vector_ref_vector_lcs_vec_csv.txt";
	string result_path = (string)_shared_path_LCS + "resultat_target_vector_ref_vector_lcs_vec_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LCS + "target_vector.csv";
	string ref_file = (string)_shared_path_LCS + "ref_vector.csv";
	string param_file = (string)_shared_path_LCS + "parameters_vec_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lcs",
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

TEST_F(LCS_SystemTest, LCS_character_ext) {

	string expected_file = (string)_shared_path_LCS + "expected_files" + _p + "expected_target_character_ref_character_lcs_char_ext.txt";
	string result_path = (string)_shared_path_LCS + "resultat_target_character_ref_character_lcs_char_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LCS + "target_character.ext";
	string ref_file = (string)_shared_path_LCS + "ref_character.ext";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lcs",
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

TEST_F(LCS_SystemTest, LCS_numeric_ext) {

	string expected_file = (string)_shared_path_LCS + "expected_files" + _p + "expected_target_numeric_ref_numeric_lcs_num_ext.txt";
	string result_path = (string)_shared_path_LCS + "resultat_target_numeric_ref_numeric_lcs_num_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LCS + "target_numeric.ext";
	string ref_file = (string)_shared_path_LCS + "ref_numeric.ext";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lcs",
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

TEST_F(LCS_SystemTest, LCS_vector_ext) {

	string expected_file = (string)_shared_path_LCS + "expected_files" + _p + "expected_target_vector_ref_vector_lcs_vec_ext.txt";
	string result_path = (string)_shared_path_LCS + "resultat_target_vector_ref_vector_lcs_vec_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LCS + "target_vector.ext";
	string ref_file = (string)_shared_path_LCS + "ref_vector.ext";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lcs",
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

TEST_F(LCS_SystemTest, LCS_character_xml) {

	string expected_file = (string)_shared_path_LCS + "expected_files" + _p + "expected_target_character_ref_character_lcs_char_xml.txt";
	string result_path = (string)_shared_path_LCS + "resultat_target_character_ref_character_lcs_char_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LCS + "target_character.xml";
	string ref_file = (string)_shared_path_LCS + "ref_character.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lcs",
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

TEST_F(LCS_SystemTest, LCS_numeric_xml) {

	string expected_file = (string)_shared_path_LCS + "expected_files" + _p + "expected_target_numeric_ref_numeric_lcs_num_xml.txt";
	string result_path = (string)_shared_path_LCS + "resultat_target_numeric_ref_numeric_lcs_num_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LCS + "target_numeric.xml";
	string ref_file = (string)_shared_path_LCS + "ref_numeric.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lcs",
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

TEST_F(LCS_SystemTest, LCS_vector_xml) {

	string expected_file = (string)_shared_path_LCS + "expected_files" + _p + "expected_target_vector_ref_vector_lcs_vec_xml.txt";
	string result_path = (string)_shared_path_LCS + "resultat_target_vector_ref_vector_lcs_vec_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LCS + "target_vector.xml";
	string ref_file = (string)_shared_path_LCS + "ref_vector.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lcs",
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
