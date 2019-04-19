#include "Wallet.h"
#include "ExceptionWalletZero.h"
#include "ExceptionWalletOutOfBounds.h"
#include "Currency.h"
#include "Dollar.h"
#include "Euro.h"
#include "Yen.h"
#include "Rupee.h"
#include "Yuan.h"

Wallet::Wallet() {};

Wallet::Wallet(double dol, double eu, double ye, double ru, double yu)
{
	dollar = new Dollar(static_cast<int>(dol), static_cast<int>((dol - static_cast<int>(dol)) * 100));
	euro = new Euro(static_cast<int>(eu), static_cast<int>((eu - static_cast<int>(eu)) * 100));
	yen = new Yen(static_cast<int>(ye), static_cast<int>((ye - static_cast<int>(ye)) * 100));
	rupee = new Rupee(static_cast<int>(ru), static_cast<int>((ru - static_cast<int>(ru)) * 100));
	yuan = new Yuan(static_cast<int>(yu), static_cast<int>((yu - static_cast<int>(yu)) * 100));
}

Wallet::~Wallet()
{
	delete dollar;
	delete euro;
	delete yen;
	delete rupee;
	delete yuan;
}

int Wallet::getNumZeroCurrency()
{
	int num = 0;

	for (int i = 0; i < 5; i++)
	{
		if ((*this)[i].isEmpty())
		{
			num++;
		}
	}

	return num;
}

//Gets the number of currencies that are not 0.0
int Wallet::getNumNonZeroCurrency()
{
	int num = 0;

	for(int i = 0; i < 5; i++)
	{
		if (!(*this)[i].isEmpty())
		{
			num++;
		}
	}

	return num;
}

//Adds currency to the wallet class with currency functions
void Wallet::addCurrency(int index, double amount)
{
	(*this)[index].addWhole(amount);
}

//Adds currency to the wallet class with currency functions
void Wallet::addCurrency(std::string abbr, double amount, double amount2)
{
	for (int i = 0; i < 5; i++)
	{
		if ((*this)[i].getCurrencyAbbreviation() == abbr)
		{
			(*this)[i].addWhole(amount);
			(*this)[i].addFractional(amount2);
		}
	}
}

//Remove function
void Wallet::removeCurrency(int index, double amount)
{
	(*this)[index].addWhole(-amount);
}

//Removes the quantity of the desire currency
void Wallet::removeCurrency(std::string abbr, double amount, double amount2)
{
	for (int i = 0; i < 5; i++)
	{
		if ((*this)[i].getCurrencyAbbreviation() == abbr)
		{
			(*this)[i].addWhole(-amount);
			(*this)[i].addWhole(-amount2);
		}
	}
}

void Wallet::emptyCurrency(int index)
{
	(*this)[index].empty();
}

void Wallet::emptyCurrency(std::string abbr)
{
	for (int i = 0; i < 5; i++)
	{
		if ((*this)[i].getCurrencyAbbreviation() == abbr)
		{
			(*this)[i].empty();
		}
	}
}

//sets all whole and fractionalparts to 0.
void Wallet::emptyAllCurrency()
{
	dollar->empty();
	euro->empty();
	yen->empty();
	rupee->empty();
	yuan->empty();
}

//Checks if wallet is empty.
bool Wallet::isWalletEmpty()
{
	for (int i = 0; i < 5; i++)
	{
		if (!(*this)[i].isEmpty())
		{
			//Something in the wallet wasn't empty so return false
			return false;
		}
	}
	//Everything in the wallet was empty so return true
	return true;
}


//Checks if currency is not zero
bool Wallet::isCurrencyEmpty(int index)
{
	if ((*this)[index].isEmpty())
	{
		return false;
	}
	else
	return true;
}

bool Wallet::isCurrencyEmpty(std::string abbr)
{
	for (int i = 0; i < 5; i++)
	{
		if ((*this)[i].getCurrencyAbbreviation() == abbr)
		{
			if (!(*this)[i].isEmpty())
			{
				return false;
			}
		}
	}

	return true;
}

Currency& Wallet::operator[](const int index)
{
	if (index == 0)
	{
		return *dollar;
	}
	else if (index == 1)
	{
		return *euro;
	}
	else if (index == 2)
	{
		return *yen;
	}
	else if (index == 3)
	{
		return *rupee;
	}
	else if (index == 4)
	{
		return *yuan;
	}
	else
	{
		throw ExceptionWalletOutOfBounds();
	}
}