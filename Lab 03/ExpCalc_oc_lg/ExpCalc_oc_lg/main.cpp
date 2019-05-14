/*
CIS 22C
Lab 03: Create a class that can convert infix expressions into postfix and prefix expressions.
Authors:
Olivier Chan Sion Moy
Luis Guerrero
*/

#include <iostream>
#include "Calculator.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
	Calculator calc;

	//cout << calc.getNext("123 - 1123 + 456");
	cout << calc.getNumberOfTokens("1 2334- 34 - 32 /                  234  % 0 ( < 8 >");
	
	cin.get();
	return 0;
}