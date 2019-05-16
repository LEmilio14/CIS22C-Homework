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

	string expression = "4 + ( 9 / 4 - 2 % 3 ) + ( 5 - 2 ) * 3";

	string* postfix = calc.infixToPostfix(expression);

	cout << calc.arrayToString(postfix) << endl;
	cout << calc.resolvePostfix(postfix) << endl;

	delete [] postfix;

	cout << endl;

	string* reverse = calc.reverseString(expression);

	for (int i = 0; i < 3; i++)
	{
		cout << reverse[i];
	}
	

	cin.get();
	return 0;
}