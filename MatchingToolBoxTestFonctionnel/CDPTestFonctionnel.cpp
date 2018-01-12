#include "CDPTestFonctionnel.h"

TEST_F(CDP_SystemTest, CDP_character_csv) {

	string expected_file = (string)_shared_path_CDP + "expected_files" + _p + "expected_target_character_ref_character_cdp_char_csv.txt";
	string result_path = (string)_shared_path_CDP + "resultat_target_character_ref_character_cdp_char_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_CDP + "target_character.csv";
	string ref_file = (string)_shared_path_CDP + "ref_character.csv";
	string param_file = (string)_shared_path_CDP + "parameters_char_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			&target_file[0u],
			&ref_file[0u],
			"-method",
			"cdp",
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

TEST_F(CDP_SystemTest, CDP_numeric_csv) {

	string expected_file = (string)_shared_path_CDP + "expected_files" + _p + "expected_target_numeric_ref_numeric_cdp_num_csv.txt";
	string result_path = (string)_shared_path_CDP + "resultat_target_numeric_ref_numeric_cdp_num_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_CDP + "target_numeric.csv";
	string ref_file = (string)_shared_path_CDP + "ref_numeric.csv";
	string param_file = (string)_shared_path_CDP + "parameters_num_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			&target_file[0u],
			&ref_file[0u],
			"-method",
			"cdp",
			"-parser",
			"csv",
			"-type",
			"numeric",
			"-param",
			&param_file[0u],
			"-result",
			&result_path[0u]};

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);

	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(CDP_SystemTest, CDP_vector_csv) {

	string expected_file = (string)_shared_path_CDP + "expected_files" + _p + "expected_target_vector_ref_vector_cdp_vec_csv.txt";
	string result_path = (string)_shared_path_CDP + "resultat_target_vector_ref_vector_cdp_vec_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_CDP + "target_vector.csv";
	string ref_file = (string)_shared_path_CDP + "ref_vector.csv";
	string param_file = (string)_shared_path_CDP + "parameters_vec_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			&target_file[0u],
			&ref_file[0u],
			"-method",
			"cdp",
			"-parser",
			"csv",
			"-type",
			"vector",
			"-param",
			&param_file[0u],
			"-result",
			&result_path[0u]};

	commandline::CommandLineApplication c = commandline::CommandLineApplication(14, args);

	ASSERT_NO_THROW(c.run());

	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(CDP_SystemTest, CDP_character_ext) {

	string expected_file = (string)_shared_path_CDP + "expected_files" + _p + "expected_target_character_ref_character_cdp_char_ext.txt";
	string result_path = (string)_shared_path_CDP + "resultat_target_character_ref_character_cdp_char_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_CDP + "target_character.ext";
	string ref_file = (string)_shared_path_CDP + "ref_character.ext";
	string param_file = (string)_shared_path_CDP + "parameters_char_ext.xml";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			&target_file[0u],
			&ref_file[0u],
			"-method",
			"cdp",
			"-parser",
			"ext",
			"-type",
			"character",
			"-result",
			&result_path[0u]};

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(CDP_SystemTest, CDP_numeric_ext) {

	string expected_file = (string)_shared_path_CDP + "expected_files" + _p + "expected_target_numeric_ref_numeric_cdp_num_ext.txt";
	string result_path = (string)_shared_path_CDP + "resultat_target_numeric_ref_numeric_cdp_num_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_CDP + "target_numeric.ext";
	string ref_file = (string)_shared_path_CDP + "ref_numeric.ext";
	string param_file = (string)_shared_path_CDP + "parameters_num_ext.xml";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			&target_file[0u],
			&ref_file[0u],
			"-method",
			"cdp",
			"-parser",
			"ext",
			"-type",
			"numeric",
			"-result",
			&result_path[0u]};

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(CDP_SystemTest, CDP_vector_ext) {

	string expected_file = (string)_shared_path_CDP + "expected_files" + _p + "expected_target_vector_ref_vector_cdp_vec_ext.txt";
	string result_path = (string)_shared_path_CDP + "resultat_target_vector_ref_vector_cdp_vec_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_CDP + "target_vector.ext";
	string ref_file = (string)_shared_path_CDP + "ref_vector.ext";
	string param_file = (string)_shared_path_CDP + "parameters_vec_ext.xml";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			&target_file[0u],
			&ref_file[0u],
			"-method",
			"cdp",
			"-parser",
			"ext",
			"-type",
			"vector",
			"-result",
			&result_path[0u]};

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(CDP_SystemTest, CDP_character_xml) {

	string expected_file = (string)_shared_path_CDP + "expected_files" + _p + "expected_target_character_ref_character_cdp_char_xml.txt";
	string result_path = (string)_shared_path_CDP + "resultat_target_character_ref_character_cdp_char_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_CDP + "target_character.xml";
	string ref_file = (string)_shared_path_CDP + "ref_character.xml";
	string param_file = (string)_shared_path_CDP + "parameters_char_xml.xml";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			&target_file[0u],
			&ref_file[0u],
			"-method",
			"cdp",
			"-parser",
			"xml",
			"-type",
			"character",
			"-result",
			&result_path[0u]};

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(CDP_SystemTest, CDP_numeric_xml) {

	string expected_file = (string)_shared_path_CDP + "expected_files" + _p + "expected_target_numeric_ref_numeric_cdp_num_xml.txt";
	string result_path = (string)_shared_path_CDP + "resultat_target_numeric_ref_numeric_cdp_num_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_CDP + "target_numeric.xml";
	string ref_file = (string)_shared_path_CDP + "ref_numeric.xml";
	string param_file = (string)_shared_path_CDP + "parameters_num_xml.xml";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			&target_file[0u],
			&ref_file[0u],
			"-method",
			"cdp",
			"-parser",
			"xml",
			"-type",
			"numeric",
			"-result",
			&result_path[0u]};

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}

TEST_F(CDP_SystemTest, CDP_vector_xml) {

	string expected_file = (string)_shared_path_CDP + "expected_files" + _p + "expected_target_vector_ref_vector_cdp_vec_xml.txt";
	string result_path = (string)_shared_path_CDP + "resultat_target_vector_ref_vector_cdp_vec_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_CDP + "target_vector.xml";
	string ref_file = (string)_shared_path_CDP + "ref_vector.xml";
	string param_file = (string)_shared_path_CDP + "parameters_vec_xml.xml";
	char* args[] = { "MatchingToolBox.exe",
			"-sequences",
			&target_file[0u],
			&ref_file[0u],
			"-method",
			"cdp",
			"-parser",
			"xml",
			"-type",
			"vector",
			"-result",
			&result_path[0u]};

	commandline::CommandLineApplication c = commandline::CommandLineApplication(12, args);
	ASSERT_NO_THROW(c.run());
	Readfile r(expected_file, result_file);

	ASSERT_EQ(r.compareFile(), true);
}
