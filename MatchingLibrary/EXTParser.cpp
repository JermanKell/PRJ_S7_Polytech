/*!
\author Bastien Meunier
\date 20/01/2015
*/

#include "EXTParser.h"
#include "XMLParser.h"
using namespace inout;

/*!
*\brief readFile
* Reads a file, parse it in a RapidXML object
*\param doc : file name
*\return the object
*/
void* EXTParser::readFile(void* document) {
	FILE* doc;
	char* docname = (char*)document;
	if ((doc = fopen(docname, "r")) == 0) {
		exc::SequenceMatchingException::genererException(
			"CSV Reading error : unable to open the file", ERREUR_FILE, __LINE__);
	}
	// Copy file content into file
	fseek(doc, 0, SEEK_END);
	size_t size = ftell(doc);

	char* where = new char[size + 1];
	where[size] = '\0';
	rewind(doc);
	fread(where, sizeof(char), size, doc);
	fclose(doc);
	string st(where);
	free(where);

	// Split string into string vector
	vector<string> strlist;

	string parsed;
	string line;
	stringstream input_stringstreamLine(st);
	bool goodVecteur = false;
	while (getline(input_stringstreamLine, line)) {
		if (line.length() > 1) {
			stringstream input_stringstream(line);
			while (getline(input_stringstream, parsed, ' ')) {
				if (parsed.length() != 0) {
					goodVecteur = true;
					strlist.push_back(parsed);
				}
			}
			if (goodVecteur) {
				strlist.push_back("NEXT");
				goodVecteur = false;
			}
		}
	}
	while ((strlist.at(strlist.size() - 1).compare("NEXT") != 0) &&
		strlist.size() > 1) {
		strlist.erase(strlist.end() - 1);
	}
	strlist.erase(strlist.end() - 1);
	strlist.push_back("END");

	// Create rapidxml sequence
	rapidxml::xml_document<>* docr = new rapidxml::xml_document<char>();
	rapidxml::xml_node<>* decl = docr->allocate_node(rapidxml::node_declaration);
	decl->append_attribute(docr->allocate_attribute("version", "1.0"));
	decl->append_attribute(docr->allocate_attribute("encoding", "utf-8"));
	docr->append_node(decl);
	// root node Sequences
	rapidxml::xml_node<>* sequences_root =
		docr->allocate_node(rapidxml::node_element, "Sequences");
	docr->append_node(sequences_root);
	// root node type
	rapidxml::xml_node<>* type_root =
		docr->allocate_node(rapidxml::node_element, "Type");
	char* strtype = new char[2];
	strtype[1] = '\0';
	sprintf(strtype, "%d", type);
	listPoubelle.push_back(strtype);

	rapidxml::xml_attribute<>* attr = docr->allocate_attribute("id", strtype);
	type_root->append_attribute(attr);
	docr->append_node(type_root);
	// root node sequence
	rapidxml::xml_node<>* seq_root =
		docr->allocate_node(rapidxml::node_element, "Sequence");
	#if defined __linux__
		uuid_t out_ = "";
		char* strbis = new char[37];
		strbis[36] = '\0';
		uuid_generate_random(out_);
		uuid_unparse(out_, strbis);
		seq_root->append_attribute(docr->allocate_attribute("idS", strbis));
		listPoubelle.push_back(strbis);
	#elif defined _WIN32 || defined _WIN64
		// Windows Includes Here
		seq_root->append_attribute(docr->allocate_attribute("idS", "1"));
	#else
		exc::SequenceMatchingException::genererException("Unknown platform",
			ERREUR_FILE, __LINE__);
	#endif

	docr->append_node(seq_root);
	// prepare child node element & vec

	// child node
	rapidxml::xml_node<>* elt_node = 0;
	rapidxml::xml_node<>* vec_node = 0;
	int it = 0;
	int end = strlist.size() - 1;
	int cas = 0;
	while (it < end) {
		if (strlist.at(it).find("NEXT") == string::npos) {
			if (type != VECTOR) {
				elt_node = docr->allocate_node(rapidxml::node_element, "Element");
				string val = strlist.at(it);
				char* valc = new char[val.size() + 1];
				valc[val.size()] = '\0';
				unsigned int itV = 0;
				while (itV < val.size()) {
					valc[itV] = val.at(itV);
					itV = itV + 1;
				}
				elt_node->append_attribute(docr->allocate_attribute("value", valc));
				listPoubelle.push_back(valc);

				#if defined __linux__
					char* strbis = new char[37];
					strbis[36] = '\0';
					uuid_generate_random(out_);
					uuid_unparse(out_, strbis);
				#elif defined _WIN32 || defined _WIN64
					// Windows Includes Here
					char* strbis = new char[2];
					strbis[1] = '\0';
					strbis[0] = '1';
				#else
					exc::SequenceMatchingException::genererException("Unknown platform",
						ERREUR_FILE, __LINE__);
				#endif
				elt_node->append_attribute(docr->allocate_attribute("id", strbis));
				listPoubelle.push_back(strbis);
				seq_root->append_node(elt_node);
			}
			else {
				if (cas == 0) {
					elt_node = docr->allocate_node(rapidxml::node_element, "Element");

					#if defined __linux__
						uuid_t out_ = "";
						char* strbis = new char[37];
						strbis[36] = '\0';
						uuid_generate_random(out_);
						uuid_unparse(out_, strbis);
					#elif defined _WIN32 || defined _WIN64
						// Windows Includes Here
						char* strbis = new char[2];
						strbis[1] = '\0';
						strbis[0] = '1';
					#else
						exc::SequenceMatchingException::genererException(
							"Unknown platform", ERREUR_FILE, __LINE__);
					#endif

					elt_node->append_attribute(docr->allocate_attribute("id", strbis));
					listPoubelle.push_back(strbis);
					seq_root->append_node(elt_node);
					cas = 2;
				}
				if (cas == 2) {
					vec_node =
						docr->allocate_node(rapidxml::node_element, "VectorElement");
					string st = strlist.at(it);
					char* strval = new char[st.size() + 1];
					strval[st.size()] = '\0';
					unsigned int u = 0;
					while (u < st.size()) {
						strval[u] = st.at(u);
						u = u + 1;
					}
					vec_node->append_attribute(docr->allocate_attribute("value", strval));
					listPoubelle.push_back(strval);
					elt_node->append_node(vec_node);
				}
			}
		}
		else {
			// Next element
			if (type != VECTOR) {
				seq_root = docr->allocate_node(rapidxml::node_element, "Sequence");
				#if defined __linux__
					uuid_t out_ = "";
					char* strbis = new char[37];
					strbis[36] = '\0';
					uuid_generate_random(out_);
					uuid_unparse(out_, strbis);
				#elif defined _WIN32 || defined _WIN64
					// Windows Includes Here
					char* strbis = new char[2];
					strbis[1] = '\0';
					strbis[0] = '1';
				#else
					exc::SequenceMatchingException::genererException("Unknown platform",
						ERREUR_FILE, __LINE__);
				#endif
				seq_root->append_attribute(docr->allocate_attribute("idS", strbis));
				listPoubelle.push_back(strbis);
				docr->append_node(seq_root);
			}
			else {
				cas = 0;
			}
		}
		it = it + 1;
	}

	// Converts the XML to vector of sequences
	inout::XMLParser* parser = new inout::XMLParser();
	void* sequences = parser->readFile(docr);

	return sequences;
}
