#pragma once
/*!
\author Abdourahman Aden Hassan
\date 20/12/2013
*/
#ifndef SEQUENCEMATCHINGEXCEPTION_H
#define SEQUENCEMATCHINGEXCEPTION_H

#include <iostream>
#include <sstream>
#include <exception>

#define FAUX 0
#define FAUX_STR "FAUX"
#define HORS_LIMITE 1
#define HORS_LIMITE_STR "HORS_LIMITE"
#define PARAMETRE_INVALIDE 2
#define PARAMETRE_INVALIDE_STR "PARAMETRE_INVALIDE"
#define ERREUR_URL 3
#define ERREUR_URL_STR "ERREUR_URL"
#define ERREUR_PARSING 4
#define ERREUR_PARSING_STR "ERREUR_PARSING"
#define ERREUR_SQL 5
#define ERREUR_SQL_STR "ERREUR_SQL"
#define ERREUR_FILE 6
#define ERREUR_FILE_STR "ERREUR_FILE"
#define ERREUR_RESULTAT 7
#define ERREUR_RESULTAT_STR "ERREUR_RESULTAT"

namespace exc {
	using namespace std;
	class SequenceMatchingException : public exception
	{
		/*!
		\class SequenceMatchingException
		\brief Cette classe repr�sente les diff�rentes exceptions lev�es par le programme
		\package exception
		*/
	private:
		/*!< Le message*/
		string strSMEmessage;


	public:
		/*!
		*  \brief Constructeur
		*  Constructeur par d�faut de la classe SequenceMatchingException
		*/
		SequenceMatchingException() {};
		/*!
		*  \brief Constructeur
		*  Constructeur � deux arguments de la classe SequenceMatchingException
		*  \param chaine : la cha�ne d'erreur
		*  \param num    : le num�ro d'erreur
		*/
		SequenceMatchingException(const string str, int num, int line) {
			ostringstream oss;
			string type;
			switch (num) {
			case HORS_LIMITE: type = HORS_LIMITE_STR; break;
			case PARAMETRE_INVALIDE: type = PARAMETRE_INVALIDE_STR; break;
			case ERREUR_PARSING: type = ERREUR_PARSING_STR; break;
			case ERREUR_FILE: type = ERREUR_FILE_STR; break;
			case ERREUR_RESULTAT: type = ERREUR_RESULTAT_STR; break;
			default: break;
			}
			oss << "Erreur ligne " << line << ", type " << type << " : " << str;
			strSMEmessage = oss.str();

		}
		/*!
		*  \brief Destructeur
		*  Destructeur de la classe SequenceMatchingException
		*/
		virtual ~SequenceMatchingException() throw() {}
		/*!
		*  \brief Red�finition de la m�thode what de la classe m�re exception
		*  \return chaine : la chaine d'erreur
		*/
		virtual const char * what() const throw() {
			return strSMEmessage.c_str();
		}
		/*!
		*  \brief virtual void genererException ()
		*  M�thode qui permet de g�n�rer l'exception
		*  \return chaine : la chaine d'erreur
		*/
		static void genererException(string chaine, int numError, int line) {
			SequenceMatchingException exc(chaine, numError, line);
			throw exc;
		}
		/*!
		*  \brief virtual void genererDialog()
		*  M�thode qui permet de g�n�rer l'exception
		*  \return chaine : la chaine d'erreur
		*/
		/*
		static void genererDialog (  string chaine,int numError){
		QString message( "Message : "+QString::fromStdString(chaine));
		QString num("Numero d'erreur : "+QString::number(numError));
		QMessageBox messageBox;
		messageBox.setText(message);
		messageBox.setWindowTitle(num);
		messageBox.exec();
		}*/
	};
}
#endif // SEQUENCEMATCHINGEXCEPTION_H
