/*!
*  \modified Bastien Meunier
*  \date 20/01/2015
*/

#include "SequenceParser.h"

#ifdef TARGET_OS_MAC
// Linux Includes Here
#include "uuid/uuid.h"
#elif defined __linux__
// Linux Includes Here
#include "uuid/uuid.h"
#endif

using namespace std;
using namespace inout;

SequenceParser::SequenceParser() { type = VECTOR; }

SequenceParser::~SequenceParser() {
	// On vide la poubelle
	unsigned int itLP = 0;
	while (itLP < listPoubelle.size()) {
		delete listPoubelle.at(itLP);
		itLP = itLP + 1;
	}
}