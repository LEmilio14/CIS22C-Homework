#include <iostream>
#include "Currency.h"

using namespace std;

int main()
{
	Currency cur1 = Currency("Dollar", "Dollars", "Cent", "Cents", 2, 50);
	Currency cur2 = Currency("Dollar", "Dollars", "Cent", "Cents", 1, 1);
	
	try
	{
		if (cur1 == cur2)
		{
			cout << "Equal" << endl;
		}
		else
		{
			cout << "Not Equal" << endl;
		}
	}
	catch (ExceptionCurrencyMismatch& e)
	{
		cout << e.what() << endl;
	}

	cout << cur1 << endl;

	cout << cur2 << endl;
	
	system("pause");
	return 0;
}