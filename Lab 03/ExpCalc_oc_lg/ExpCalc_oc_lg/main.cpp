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

	string s = "1 + 45 - 1 % ( 23 / 99 ) -42 + 65(";
	
	auto stringArr = calc.splitString(s);

	for (int i = 0; i < calc.getNumberOfTokens(s); i++)
	{
		cout << stringArr[i] << endl;
	}
	string s1 = "1 + 45 - 1 % ( 23 / 99 ) -42 + 65 + 0";
	//unique_ptr<string[]> stringArr1 = calc.splitString(s1);
	unique_ptr<string[]> result = calc.reverseString(calc.splitString(s1), s1.length());

	for (int i = 0; i < calc.getNumberOfTokens(s1); i++)
	{
		cout << result[i];
	}
	//cout << calc.getNext("123 - 1123 + 456");
	//cout << calc.getNumberOfTokens("1 2334- 34 - 32 /                  234  % 0 ( < 8 >");
	
	cin.get();
	return 0;
}