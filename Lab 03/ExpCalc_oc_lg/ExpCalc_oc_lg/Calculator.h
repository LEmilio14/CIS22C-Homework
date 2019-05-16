/********************************************************************************
********************************** Calculator ***********************************
*********************************************************************************
* This class is to be used for converting infix expressions into postfix and
* prefix expressions.
*****************
***** USAGE *****
*****************
* Infix expressions should be strings, with operands and operators separated by
* spaces. Allowed operators are +, -, *, /, %, (, ). Negation is not allowed.
* Examples:
* "1 + 2" (legal)
* "( 12 - 34 )" (legal)
* "123 % 456" (legal)
* "(123 / 456)" (illegal: parentheses are not seperated by spaces)
* "-23 + 46" (illegal: unary operator negation "-" not allowed)
*********************************************************************************/

#pragma once

#include <string>
#include <memory>

#include "ExceptionMalformedExpression.h"
#include "Stack.h"
#include "Queue.h"

class Calculator
{
private:
	std::string* splitString(std::string);
	std::string* reverseString(std::string);
	bool isOperator(std::string);
	bool isOperand(std::string);
	int getNumberOfTokens(std::string);
	int getOperatorPrecedence(std::string);
	void validateExpression(std::string);
public:
	/**
	* infixToPostfix
	*
	* @brief Converts a string infix expression into an array of string tokens (operands and operators) in postfix order. The array is terminated with the string "\0".
	*
	* @param infix A string infix expression, with all separate operands and operators separated by spaces. An invalid expression will cause an exception.
	*
	* @return A dynamic array of tokens in postfix order. The array is terminated with the string "\0". This array must be properly deallocated.
	*/
	std::string* infixToPostfix(std::string);
	std::string* infixToPrefix(std::string);

	/**
	* resolvePostfix
	*
	* @brief Calculates the result of a postfix expression, given the postfix expression as an array of tokens.
	*
	* @param postfixArray The postfix expression as an array. This array should be created by infixToPostfix().
	*
	* @return The resulting evaluation of the postfix expression.
	*/
	int resolvePostfix(std::string*);
	int resolvePrefix(Stack<std::string>, Queue<std::string>);
	
	/**
	* arrayToString
	*
	* @brief Convert an expression array into a string representation.
	*
	* @param array The expression array to convert. This array should be created by infixToPostfix() or infixToPrefix().
	*
	* @return The string representation of the expression array.
	*/
	std::string arrayToString(std::string*);
};