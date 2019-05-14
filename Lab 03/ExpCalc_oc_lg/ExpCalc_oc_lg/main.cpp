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

	cout << calc.getNext("1 + 456");
	
	cin.get();
	return 0;
}