#include "MVMTestFonctionnel.h"

TEST_F(MVM_SystemTest, MVM_character_csv) {

	string expected_file = (string)_shared_path_MVM + "expected_files" + _p + "expected_target_character_ref_character_mvm_char_csv.txt";
	string result_path = (string)_shared_path_MVM + "resultat_target_character_ref_character_mvm_char_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_MVM + "target_character.csv";
	string ref_file = (string)_shared_path_MVM + "ref_character.csv";
	string param_file = (string)_shared_path_MVM + "parameters_char_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"mvm",
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

TEST_F(MVM_SystemTest, MVM_numeric_csv) {

	string expected_file = (string)_shared_path_MVM + "expected_files" + _p + "expected_target_numeric_ref_numeric_mvm_num_csv.txt";
	string result_path = (string)_shared_path_MVM + "resultat_target_numeric_ref_numeric_mvm_num_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_MVM + "target_numeric.csv";
	string ref_file = (string)_shared_path_MVM + "ref_numeric.csv";
	string param_file = (string)_shared_path_MVM + "parameters_num_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"mvm",
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

TEST_F(MVM_SystemTest, MVM_vector_csv) {

	string expected_file = (string)_shared_path_MVM + "expected_files" + _p + "expected_target_vector_ref_vector_mvm_vec_csv.txt";
	string result_path = (string)_shared_path_MVM + "resultat_target_vector_ref_vector_mvm_vec_csv";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_MVM + "target_vector.csv";
	string ref_file = (string)_shared_path_MVM + "ref_vector.csv";
	string param_file = (string)_shared_path_MVM + "parameters_vec_csv.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"mvm",
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

TEST_F(MVM_SystemTest, MVM_character_ext) {

	string expected_file = (string)_shared_path_MVM + "expected_files" + _p + "expected_target_character_ref_character_mvm_char_ext.txt";
	string result_path = (string)_shared_path_MVM + "resultat_target_character_ref_character_mvm_char_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_MVM + "target_character.ext";
	string ref_file = (string)_shared_path_MVM + "ref_character.ext";
	string param_file = (string)_shared_path_MVM + "parameters_char_ext.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"mvm",
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

TEST_F(MVM_SystemTest, MVM_numeric_ext) {

	string expected_file = (string)_shared_path_MVM + "expected_files" + _p + "expected_target_numeric_ref_numeric_mvm_num_ext.txt";
	string result_path = (string)_shared_path_MVM + "resultat_target_numeric_ref_numeric_mvm_num_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_MVM + "target_numeric.ext";
	string ref_file = (string)_shared_path_MVM + "ref_numeric.ext";
	string param_file = (string)_shared_path_MVM + "parameters_num_ext.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"mvm",
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

TEST_F(MVM_SystemTest, MVM_vector_ext) {

	string expected_file = (string)_shared_path_MVM + "expected_files" + _p + "expected_target_vector_ref_vector_mvm_vec_ext.txt";
	string result_path = (string)_shared_path_MVM + "resultat_target_vector_ref_vector_mvm_vec_ext";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_MVM + "target_vector.ext";
	string ref_file = (string)_shared_path_MVM + "ref_vector.ext";
	string param_file = (string)_shared_path_MVM + "parameters_vec_ext.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"mvm",
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

TEST_F(MVM_SystemTest, MVM_character_xml) {

	string expected_file = (string)_shared_path_MVM + "expected_files" + _p + "expected_target_character_ref_character_mvm_char_xml.txt";
	string result_path = (string)_shared_path_MVM + "resultat_target_character_ref_character_mvm_char_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_MVM + "target_character.xml";
	string ref_file = (string)_shared_path_MVM + "ref_character.xml";
	string param_file = (string)_shared_path_MVM + "parameters_char_xml.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"mvm",
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

TEST_F(MVM_SystemTest, MVM_numeric_xml) {

	string expected_file = (string)_shared_path_MVM + "expected_files" + _p + "expected_target_numeric_ref_numeric_mvm_num_xml.txt";
	string result_path = (string)_shared_path_MVM + "resultat_target_numeric_ref_numeric_mvm_num_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_MVM + "target_numeric.xml";
	string ref_file = (string)_shared_path_MVM + "ref_numeric.xml";
	string param_file = (string)_shared_path_MVM + "parameters_num_xml.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"mvm",
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

TEST_F(MVM_SystemTest, MVM_vector_xml) {

	string expected_file = (string)_shared_path_MVM + "expected_files" + _p + "expected_target_vector_ref_vector_mvm_vec_xml.txt";
	string result_path = (string)_shared_path_MVM + "resultat_target_vector_ref_vector_mvm_vec_xml";
	string result_file = result_path + _p + "1.txt";
	string target_file = (string)_shared_path_MVM + "target_vector.xml";
	string ref_file = (string)_shared_path_MVM + "ref_vector.xml";
	string param_file = (string)_shared_path_MVM + "parameters_vec_xml.xml";
	char* args[] = { "MatchingToolBox.exe",
		"-sequences",
		&target_file[0u],
		&ref_file[0u],
		"-method",
		"mvm",
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