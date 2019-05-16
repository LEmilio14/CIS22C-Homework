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

#include <iostream>

#include <string>
#include <memory>
#include "ExceptionMalformedExpression.h"
#include "Stack.h"
#include "Queue.h"

class Calculator
{
private:
	
public:
	std::unique_ptr<std::string[]> splitString(std::string);
	std::unique_ptr<std::string[]> expressionToPostFix(std::unique_ptr<std::string[]>, int);
	std::unique_ptr<std::string[]> infixToPrefix(std::unique_ptr<std::string[]>&, int);
	int getNumberOfTokens(std::string);
	bool isOperator(std::string);
	bool isOperand(std::string);
	int getOperatorPrecedence(std::string);
	void reverseString(std::unique_ptr<std::string[]>&, int);
	Calculator();
	~Calculator();
};