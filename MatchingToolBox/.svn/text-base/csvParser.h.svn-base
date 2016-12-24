/*!
  \author Abdourahman Aden Hassan
  \date 24/12/2013
  \modified Bastien Meunier
  \date 20/01/2015
 */
#ifndef CSVPARSER_H
#define CSVPARSER_H
#include "sequenceparser.h"
#include <string>
namespace inout {
using namespace std;
class CSVParser : public SequenceParser
{
    /*! \interface CSVParser
        \brief Cette interface définit le parsage CSV de notre application en fichier XML
     * \package inout
    */
public:
	CSVParser() : SequenceParser(){}
	virtual ~CSVParser(){};

	virtual void * readFile(void * document);
};

}
#endif // CSVPARSER_H
