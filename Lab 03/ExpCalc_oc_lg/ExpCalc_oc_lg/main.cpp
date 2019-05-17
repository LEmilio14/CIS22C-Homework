/*
CIS 22C
Lab 03: Create a class that can convert infix expressions into postfix and prefix expressions.
Authors:
Olivier Chan Sion Moy
Luis Guerrero
*/

#include <iostream>

#include "Calculator.h"

using namespace std;

int main()
{
	Calculator calc;

	//Get user inputted expression
	string expression;
	cout << "Enter an expression." << endl
		<< "Operators and operands must be separated by spaces." << endl
		<< "Allowed operators: +, -, *, /, %, (, ). Negation is not allowed." << endl;
	cin >> expression;
	cin.ignore();

	//Convert expression to postfix, then print out postfix expression and calculate
	string* postfix = calc.infixToPostfix(expression);

	cout << "Postfix Expression:" << endl;
	cout << calc.arrayToString(postfix) << endl;
	cout << "Postfix Result:" << endl;
	cout << calc.resolvePostfix(postfix) << endl;

	//Convert expression to prefix, then print out prefix expression and calculate
	//string* prefix = calc.infixToPrefix(expression);

	//cout << "Prefix Expression:" << endl;
	//cout << calc.arrayToString(prefix) << endl;
	//cout << "Prefix Result:" << endl;
	//cout << calc.resolvePrefix(prefix) << endl;

	delete [] postfix;
	//delete [] prefix;

	cin.get();
	return 0;
}