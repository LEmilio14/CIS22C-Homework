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

	auto postfix = calc.infixToPostfix(expression);

	int i = 0;
	
	while (postfix[i] != "\0")
	{
		cout << postfix[i] << endl;
		i++;
	}

	cout << endl;

	string* reverse = calc.reverseString(expression);

	for (int i = 0; i < 19; i++)
	{
		cout << reverse[i];
	}
	

	cin.get();
	return 0;
}