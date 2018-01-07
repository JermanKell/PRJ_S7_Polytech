#if defined _WIN32 || defined _WIN64
    #include "CSVParser.h"
    #include "XMLParser.h"
    #include "gtest\gtest.h"
#elif defined __linux__
    #include "../MatchingLibrary/CSVParser.h"
    #include "../MatchingLibrary/XMLParser.h"
    #include "gtest/gtest.h"
#endif


TEST(CSVParserTest, setting_getting_sequence_type) {
	inout::CSVParser parser;

	parser.setType(inout::SEQUENCE_TYPE::NUMERIC);
	ASSERT_EQ(parser.getType(), inout::SEQUENCE_TYPE::NUMERIC);

	parser.setType(inout::SEQUENCE_TYPE::CHARACTER);
	ASSERT_EQ(parser.getType(), inout::SEQUENCE_TYPE::CHARACTER);

	parser.setType(inout::SEQUENCE_TYPE::VECTOR);
	ASSERT_EQ(parser.getType(), inout::SEQUENCE_TYPE::VECTOR);
}

TEST(CSVParserTest, reading_numeric_csv_file) {
	char* filename = "..\\TestingMaterial\\ref_numeric.csv";
	inout::CSVParser parser;
	parser.setType(inout::SEQUENCE_TYPE::NUMERIC);
	std::vector<model::Sequence *> * sequences = (std::vector<model::Sequence *> *) parser.readFile(filename);

	// There should be one sequence
	ASSERT_EQ(sequences->size(), 1);

	// The sequence should have 5 numbers
	ASSERT_EQ(sequences->at(0)->getSize(), 5);

	for (unsigned int uiCount = 0; uiCount < sequences->size(); uiCount++) {	//boucle for ajouté
		delete sequences->at(uiCount);
	}
	delete sequences;	//free changé par delete
}

TEST(CSVParserTest, reading_vector_csv_file) {
	char* filename = "..\\TestingMaterial\\ref_vector.csv";
	inout::CSVParser parser;
	parser.setType(inout::SEQUENCE_TYPE::VECTOR);
	std::vector<model::Sequence *> * sequences = (std::vector<model::Sequence *> *) parser.readFile(filename);

	// There should be one sequence
	ASSERT_EQ(sequences->size(), 1);

	// The sequence should have 367 numbers
	ASSERT_EQ(sequences->at(0)->getSize(), 367);

	for (unsigned int uiCount = 0; uiCount < sequences->size(); uiCount++) {	//boucle for ajouté
		delete sequences->at(uiCount);
	}
	delete sequences;	//free changé par delete
}

TEST(CSVParserTest, reading_character_csv_file) {
	char* filename = "..\\TestingMaterial\\ref_character.csv";
	inout::CSVParser parser;
	parser.setType(inout::SEQUENCE_TYPE::CHARACTER);
	std::vector<model::Sequence *> * sequences = (std::vector<model::Sequence *> *) parser.readFile(filename);

	// There should be 2 sequences
	ASSERT_EQ(sequences->size(), 2);

	// The sequence should have 5 numbers
	ASSERT_EQ(sequences->at(0)->getSize(), 5);

	for (unsigned int uiCount = 0; uiCount < sequences->size(); uiCount++) {	//boucle for ajouté
		delete sequences->at(uiCount);
	}
	delete sequences;	//free changé par delete
}
