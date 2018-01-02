#include "XMLParser.h"
#include "gtest\gtest.h"

TEST(XMLParserTest, reading_character_xml_files) {
	char* filename = "..\\TestingMaterial\\sequence_of_character.xml";
	// Opening the file
	rapidxml::file<> xmlFile(filename);
	rapidxml::xml_document<> doc;
	doc.parse<0>(xmlFile.data());
	inout::XMLParser parser;
	std::vector<model::Sequence *> *sequences = (std::vector<model::Sequence *> *) parser.readFile(&doc);

	model::Sequence* firstSequence = sequences->at(0);
	EXPECT_EQ(firstSequence->getSize(), 2);

	char value = ((model::Character*) firstSequence->getElement(0))->getValue();
	EXPECT_EQ(value, 'a');

	value = ((model::Character*) firstSequence->getElement(1))->getValue();
	EXPECT_EQ(value, 'b');

	for (unsigned int uiCount = 0; uiCount < sequences->size(); uiCount++) {	//boucle for ajouté
		delete sequences->at(uiCount);
	}
	delete sequences;	//ajouté
	doc.clear();
}

TEST(XMLParserTest, reading_numeric_xml_files) {
	char* filename = "..\\TestingMaterial\\sequence_of_numeric.xml";
	// Opening the file
	rapidxml::file<> xmlFile(filename);
	rapidxml::xml_document<> doc;
	doc.parse<0>(xmlFile.data());
	inout::XMLParser parser;
	std::vector<model::Sequence *> *sequences = (std::vector<model::Sequence *> *) parser.readFile(&doc);

	model::Sequence* firstSequence = sequences->at(0);
	EXPECT_EQ(firstSequence->getSize(), 2);

	float value = ((model::Numeric*) firstSequence->getElement(0))->getValue();
	EXPECT_EQ(value, 5);

	value = ((model::Numeric*) firstSequence->getElement(1))->getValue();
	EXPECT_EQ(value, 4);

	for (unsigned int uiCount = 0; uiCount < sequences->size(); uiCount++) {	//boucle for ajouté
		delete sequences->at(uiCount);
	}
	delete sequences;	//ajouté
	doc.clear();
}

TEST(XMLParserTest, reading_vector_xml_files) {
	char* filename = "..\\TestingMaterial\\sequence_of_vector.xml";
	// Opening the file
	rapidxml::file<> xmlFile(filename);
	rapidxml::xml_document<> doc;
	doc.parse<0>(xmlFile.data());
	inout::XMLParser parser;
	std::vector<model::Sequence *> *sequences = (std::vector<model::Sequence *> *) parser.readFile(&doc);

	model::Sequence* firstSequence = sequences->at(0);
	EXPECT_EQ(firstSequence->getSize(), 2);

	model::CharacteristicVector* element = (model::CharacteristicVector*) firstSequence->getElement(0);
	int nb = element->getSize();
	EXPECT_EQ(nb, 2);
	EXPECT_EQ(element->getAt(0), 1);
	EXPECT_EQ(element->getAt(1), 2);

	element = (model::CharacteristicVector*) firstSequence->getElement(1);
	nb = element->getSize();
	EXPECT_EQ(nb, 1);
	EXPECT_EQ(element->getAt(0), 3);

	for (unsigned int uiCount = 0; uiCount < sequences->size(); uiCount++) {	//boucle for ajouté
		delete sequences->at(uiCount);
	}
	delete sequences;	//ajouté
	doc.clear();
}