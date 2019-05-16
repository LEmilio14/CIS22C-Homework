/********************************************************************************
********************************** Calculator ***********************************
*********************************************************************************
* This class is to be used for converting infix expressions into postfix and
* prefix expressions.
*****************
***** USAGE *****
*****************
* Infix expressions should be strings, with operands and operators seperated by
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

#include <iostream>

#include "ExceptionMalformedExpression.h"
#include "Stack.h"
#include "Queue.h"

class Calculator
{
private:
	
public:
	std::string* splitString(std::string);
	std::string* infixToPostfix(std::string);
	std::string* infixToPrefix(std::string);

	int resolvePostfix(std::string*);
	int resolvePrefix(Stack<std::string>, Queue<std::string>);
	
	bool isOperator(std::string);
	bool isOperand(std::string);
	int getNumberOfTokens(std::string);
	int getOperatorPrecedence(std::string);
	std::string* reverseString(std::string);
	std::string arrayToString(std::string*);
	void validateExpression(std::string);
	Calculator();
	~Calculator();
};