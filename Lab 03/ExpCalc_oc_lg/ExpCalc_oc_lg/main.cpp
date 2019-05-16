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

	string s = "1 + 45 - 7 % ( 23 / 99 )";

	//calc.expressionToPostFix(calc.splitString(s), calc.getNumberOfTokens(s));

	unique_ptr<string[]> string2 = calc.splitString(s);
	calc.reverseString(string2, calc.getNumberOfTokens(s));
	for (int i = 0; i < calc.getNumberOfTokens(s); i++)
	{
		cout << string2[i];
	}

	calc.infixToPrefix(string2, calc.getNumberOfTokens(s));
	
	//cout << calc.getNext("123 - 1123 + 456");
	//cout << calc.getNumberOfTokens("1 2334- 34 - 32 /                  234  % 0 ( < 8 >");
	
	cin.get();
	return 0;
}