#include "LevenshteinTestFonctionnel.h"

TEST_F(Levenshtein_SystemTest, levenshtein_character_csv) {

	string expected_file = (string)_shared_path_LEVENSHTEIN + "expected_files" +  _p + "expected_target_character_ref_character_lvn_char_csv.txt";
	string result_path = (string)_shared_path_LEVENSHTEIN + "resultat_target_character_ref_character_lvn_char_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LEVENSHTEIN + "target_character.csv";
	string ref_file = (string)_shared_path_LEVENSHTEIN + "ref_character.csv";
	string param_file = (string)_shared_path_LEVENSHTEIN + "parameters_char_csv.xml";
	char* args[] = {"MatchingToolBox.exe",
			"-sequences",
			&target_file[0u],
			&ref_file[0u],
			"-method",
			"lvn",
			"-parser",
			"csv",
			"-type",
			"character",
			"-param",
			&param_file[0u],
			"-result",
			&result_path[0u]};

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);
	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(Levenshtein_SystemTest, levenshtein_numeric_csv) {

	string expected_file = (string)_shared_path_LEVENSHTEIN + "expected_files" + _p + "expected_target_numeric_ref_numeric_lvn_num_csv.txt";
	string result_path = (string)_shared_path_LEVENSHTEIN + "resultat_target_numeric_ref_numeric_lvn_num_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LEVENSHTEIN + "target_numeric.csv";
	string ref_file = (string)_shared_path_LEVENSHTEIN + "ref_numeric.csv";
	string param_file = (string)_shared_path_LEVENSHTEIN + "parameters_num_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lvn",
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

TEST_F(Levenshtein_SystemTest, levenshtein_vector_csv) {

	string expected_file = (string)_shared_path_LEVENSHTEIN + "expected_files" + _p + "expected_target_vector_ref_vector_lvn_vec_csv.txt";
	string result_path = (string)_shared_path_LEVENSHTEIN + "resultat_target_vector_ref_vector_lvn_vec_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LEVENSHTEIN + "target_vector.csv";
	string ref_file = (string)_shared_path_LEVENSHTEIN + "ref_vector.csv";
	string param_file = (string)_shared_path_LEVENSHTEIN + "parameters_vec_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lvn",
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

TEST_F(Levenshtein_SystemTest, levenshtein_character_ext) {

	string expected_file = (string)_shared_path_LEVENSHTEIN + "expected_files" + _p + "expected_target_character_ref_character_lvn_char_ext.txt";
	string result_path = (string)_shared_path_LEVENSHTEIN + "resultat_target_character_ref_character_lvn_char_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LEVENSHTEIN + "target_character.ext";
	string ref_file = (string)_shared_path_LEVENSHTEIN + "ref_character.ext";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lvn",
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

TEST_F(Levenshtein_SystemTest, levenshtein_numeric_ext) {

	string expected_file = (string)_shared_path_LEVENSHTEIN + "expected_files" + _p + "expected_target_numeric_ref_numeric_lvn_num_ext.txt";
	string result_path = (string)_shared_path_LEVENSHTEIN + "resultat_target_numeric_ref_numeric_lvn_num_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LEVENSHTEIN + "target_numeric.ext";
	string ref_file = (string)_shared_path_LEVENSHTEIN + "ref_numeric.ext";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lvn",
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

TEST_F(Levenshtein_SystemTest, levenshtein_vector_ext) {

	string expected_file = (string)_shared_path_LEVENSHTEIN + "expected_files" + _p + "expected_target_vector_ref_vector_lvn_vec_ext.txt";
	string result_path = (string)_shared_path_LEVENSHTEIN + "resultat_target_vector_ref_vector_lvn_vec_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LEVENSHTEIN + "target_vector.ext";
	string ref_file = (string)_shared_path_LEVENSHTEIN + "ref_vector.ext";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lvn",
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

TEST_F(Levenshtein_SystemTest, levenshtein_character_xml) {

	string expected_file = (string)_shared_path_LEVENSHTEIN + "expected_files" + _p + "expected_target_character_ref_character_lvn_char_xml.txt";
	string result_path = (string)_shared_path_LEVENSHTEIN + "resultat_target_character_ref_character_lvn_char_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LEVENSHTEIN + "target_character.xml";
	string ref_file = (string)_shared_path_LEVENSHTEIN + "ref_character.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lvn",
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

TEST_F(Levenshtein_SystemTest, levenshtein_numeric_xml) {

	string expected_file = (string)_shared_path_LEVENSHTEIN + "expected_files" + _p + "expected_target_numeric_ref_numeric_lvn_num_xml.txt";
	string result_path = (string)_shared_path_LEVENSHTEIN + "resultat_target_numeric_ref_numeric_lvn_num_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LEVENSHTEIN + "target_numeric.xml";
	string ref_file = (string)_shared_path_LEVENSHTEIN + "ref_numeric.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lvn",
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

TEST_F(Levenshtein_SystemTest, levenshtein_vector_xml) {

	string expected_file = (string)_shared_path_LEVENSHTEIN + "expected_files" + _p + "expected_target_vector_ref_vector_lvn_vec_xml.txt";
	string result_path = (string)_shared_path_LEVENSHTEIN + "resultat_target_vector_ref_vector_lvn_vec_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_LEVENSHTEIN + "target_vector.xml";
	string ref_file = (string)_shared_path_LEVENSHTEIN + "ref_vector.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"lvn",
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
