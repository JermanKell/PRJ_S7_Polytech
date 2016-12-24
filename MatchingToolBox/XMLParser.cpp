/*!
\author Bastien Meunier
\date 20/01/2015
*/

#include "XMLParser.h"

using namespace std;
using namespace inout;

void *XMLParser::readFile(void *document) {
	int sequenceType = -1;
	std::vector<model::Sequence *> *sequenceList = new std::vector<model::Sequence *>();
	rapidxml::xml_document<> *xmlDocument = (rapidxml::xml_document<char> *)document;
	if (xmlDocument->first_node("Sequences") == 0) {
		delete sequenceList;
		exc::SequenceMatchingException::genererException(
			"XML Reading error : Invalid file format", ERREUR_FILE, __LINE__);
	}

	// Take the type
	rapidxml::xml_node<> *type_node;
	type_node = xmlDocument->first_node("Type");
	if (type_node == 0) {
		delete sequenceList;
		exc::SequenceMatchingException::genererException(
			"XML Reading error : Invalid type node ", ERREUR_FILE, __LINE__);
	}
	// Take the type id attribute
	rapidxml::xml_attribute<> *type_attr = type_node->first_attribute("id");
	if (type_attr == 0) {
		delete sequenceList;
		exc::SequenceMatchingException::genererException(
			"XML Reading error : Invalid id attribute in type node", ERREUR_FILE, __LINE__);
	}

	sequenceType = atoi(type_attr->value());
	// Take the First sequence
	rapidxml::xml_node<> *sequence_node;
	sequence_node = xmlDocument->first_node("Sequence");
	if (sequence_node == 0) {
		delete sequenceList;
		exc::SequenceMatchingException::genererException(
			"XML Reading error : Invalid format you need a sequence node", ERREUR_FILE, __LINE__);
	}
	// Get sequences from the XML file
	do {
		// Create sequence
		model::Sequence *sequence = new model::Sequence();

		rapidxml::xml_attribute<> *id_attr = sequence_node->first_attribute("idS");
		if (id_attr == 0) {
			delete sequence;
			delete sequenceList;
			exc::SequenceMatchingException::genererException(
				"XML Reading error : Invalid id attribute in sequence node ", ERREUR_FILE,
				__LINE__);
		}
		string sid(id_attr->value(), id_attr->value_size());
		sequence->setUid(sid);
		// Get first element
		rapidxml::xml_node<> *elt_node;
		elt_node = sequence_node->first_node("Element");
		if (elt_node == 0) {
			delete sequenceList;
			delete sequence;
			exc::SequenceMatchingException::genererException(
				"XML Reading error : Invalid Element tag ", ERREUR_FILE,
				__LINE__);
		}
		if (sequenceType == CHARACTER) {

			// Iterate elements
			do {
				rapidxml::xml_attribute<> *id_attr = elt_node->first_attribute("id");
				model::Character *cha = new model::Character;
				cha->setUid(id_attr->value());
				rapidxml::xml_attribute<> *val_attr =
					elt_node->first_attribute("value");
				cha->setValue(val_attr->value()[0]);
				sequence->addElement(cha);
				elt_node = elt_node->next_sibling();
			} while (elt_node != 0);
		}
		else if (sequenceType == NUMERIC) {
			do {
				// Iterate elements
				rapidxml::xml_attribute<> *id_attr = elt_node->first_attribute("id");
				rapidxml::xml_attribute<> *val_attr =
					elt_node->first_attribute("value");
				if (id_attr == 0 || val_attr == 0) {
					delete sequenceList;
					delete sequence;
					exc::SequenceMatchingException::genererException(
						" test 8 XML Reading error : Invalid type tag ", ERREUR_FILE,
						__LINE__);
				}
				model::Numeric *nu = new model::Numeric;
				string fid(id_attr->value(), id_attr->value_size());
				nu->setUid(fid);
				string fn(val_attr->value(), val_attr->value_size());
				nu->setValue((float)atof(fn.c_str()));
				sequence->addElement(nu);
				elt_node = elt_node->next_sibling();
			} while (elt_node != 0);
		}
		else if (sequenceType == VECTOR) {
			do {
				// Iterate vector elements
				rapidxml::xml_node<> *vec_node;
				vec_node = elt_node->first_node("VectorElement");
				if (vec_node == 0) {
					delete sequence;
					delete sequenceList;
					exc::SequenceMatchingException::genererException(
						"XML Reading error : Invalid type tag ", ERREUR_FILE, __LINE__);
				}

				rapidxml::xml_attribute<> *id_attr = elt_node->first_attribute("id");
				if (id_attr == 0) {
					delete sequenceList;
					delete sequence;
					exc::SequenceMatchingException::genererException(
						"XML Reading error : Invalid type tag ", ERREUR_FILE, __LINE__);
				}
				model::CharacteristicVector *vec = new model::CharacteristicVector;
				vec->setUid(id_attr->value());
				do {
					// Iterate vector
					rapidxml::xml_attribute<> *vecval_attr =
						vec_node->first_attribute("id");
					if (vecval_attr == 0) {
						delete sequenceList;
						delete sequence;
						delete vec;
						exc::SequenceMatchingException::genererException(
							"XML Reading error : Invalid type tag ", ERREUR_FILE, __LINE__);
					}
					string vv = string(vecval_attr->value(), vecval_attr->value_size());
					vec->addValue((float)atof(vv.c_str()));
					vec_node = vec_node->next_sibling();
				} while (vec_node != 0);
				sequence->addElement(vec);
				elt_node = elt_node->next_sibling();
			} while (elt_node != 0);

		}
		else {
			delete sequence;
			delete sequenceList;
			exc::SequenceMatchingException::genererException(
				" test XML Reading error : Invalid type tag ", ERREUR_FILE, __LINE__);
		}
		// Iterate
		sequenceList->push_back(sequence);
		sequence_node = sequence_node->next_sibling();
	} while (sequence_node != 0);

	xmlDocument->clear();

	delete xmlDocument;

	return sequenceList;
}