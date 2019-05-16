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
	string* prefix = calc.infixToPrefix(expression);

	cout << calc.arrayToString(postfix) << endl;
	cout << calc.resolvePostfix(postfix) << endl;

	cout << calc.arrayToString(prefix) << endl;

<<<<<<< HEAD

	delete [] postfix;
	delete[] prefix;

	

=======
>>>>>>> d516e691126c26c69573b1d2842851f363deb256
	cin.get();
	return 0;
}