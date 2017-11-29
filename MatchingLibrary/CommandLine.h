#pragma once
/*!
\author ELMOUTARAJI Mohammed
BOUTBIB Houda
\date 22/12/2016
\package Command
\brief Commandline facilitates reading a command.
*/

#include <vector>
#include <map>

#ifndef COMMANDLINE_H
#define COMMANDLINE_H

namespace commandline {

	class CommandLine {
	protected:

		/*!< The arguments that should be expected to be present in command */
		std::vector<std::string> expectedArguments;

		/*!< The expected values of a certain argument */
		std::map<std::string, std::vector<std::string>> expectedValues;

		/*!< The arguments that actually exists in the command */
		std::vector<std::string> enteredArguments;

		/*!< The entered values of an argumant */
		std::map<std::string, std::vector<std::string>> enteredValues;

	public : 

		/*!
		*  \brief Constructor
		*  
		*  \param argc number of arguments in the command line
		*  \param argv the arguments of the command line
		*/
		CommandLine(int argc, char *argv[]);

		/*!
		* \brief expectArgument
		* Sets an argument as an expected argument
		* \param argument string
		*/
		void expectArgument(std::string argument);

		/*!
		* \brief expectValue
		* Sets a value of an argument as an expected value
		* \param argument string
		* \param value string
		*/
		void expectValue(std::string argument, std::string value);

		/*!
		* \brief expectValues
		* Sets values of an argument as expected values
		* \param argument string
		* \param nbValues number of values
		* \param values values
		*/
		void expectValues(std::string argument, unsigned int nbValues, char* values[]);

		/*!
		* \brief enterArgument
		* Enters an argument that exists in the command line
		* \param argument string
		*/
		void enterArgument(std::string argument);

		/*!
		* \brief enterValue
		* Enters a value of an argument
		* \param argument string
		* \param value string
		*/
		void enterValue(std::string argument, std::string value);

		/*!
		* \brief enterValues
		* Enters a value of an argument
		* \param argument string
		* \param nbValues number of values
		* \param values values
		*/
		void enterValues(std::string argument, unsigned int nbValues, char* values[]);

		/*!
		* \brief isExpected
		* Searches if an argument is expected
		* \param argument string
		* \return bool
		*/
		bool isExpected(std::string argument);

		/*!
		* \brief isExpected
		* Searches if a value is expected for a certain argument
		* \param argument string
		* \param value string
		* \return bool
		*/
		bool isExpected(std::string argument, std::string value);

		/*!
		* \brief isEntered
		* Searches if an argument was entered in the command line
		* \param argument string
		* \return bool
		*/
		bool isEntered(std::string argument);

		/*!
		* \brief isExpected
		* Searches if a value is entered for a certain argument
		* \param argument string
		* \param value string
		* \return bool
		*/
		bool isEntered(std::string argument, std::string value);

		/*!
		* \brief getEnteredValue
		* get the nth entered value of an argument.
		* \param argument string
		* \param position unsigned int
		* \return value string
		*/
		std::string getEnteredValue(std::string argument, unsigned int position);

		/*!
		* \brief run
		* run the program
		*/
		virtual void run() = 0;

	private : 

		/*!
		* \brief prepareCommand
		* prepares a command that means essentially extracting entered arguments and values from a command line
		* \param argc number of arguments and values in the command line
		* \param argv arguments and values
		*/
		void prepareCommand(int argc, char *argv[]);
	};
}

#endif