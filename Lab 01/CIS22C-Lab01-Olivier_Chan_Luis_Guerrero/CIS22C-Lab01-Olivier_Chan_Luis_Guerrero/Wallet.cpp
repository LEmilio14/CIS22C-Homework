#include "Wallet.h"
#include "Currency.h"
#include "ExceptionWalletZero.cpp"

Wallet::Wallet(double dol, double eu, double ye, double rup, double yu)
{

	dollar = new Currency();
	euro = new Currency();
	yen = new Currency();
	rupee = new Currency();
	yuan = new Currency();
	//yuan = new Currency("Yuan", "Yuan", "Fen", "Fens", static_cast<int>(numb), static_cast<int>(((int)numb % 100) * 100));

}

//Gets the number of currencies that are not 0.0
int Wallet::getNumbOfNonZeroCur()
{
	int numbOfNonZero;

	for(int i = 0; i < 5; i++)
	{
		if(0 == walletList[i].getWholeParts && 0 == walletList[i].getFractionalParts)
		numbOfNonZero++;
	}

	return numbOfNonZero;
}

//Adds currency to the wallet class with currency functions
void Wallet::addCurrency(Currency *currencyName, double amount)
{
	int i;
	
	for (i = 0; i < 5 ; i++)
	{
		if (amount > 0)
		{
			throw (ExceptionCurrencyNegative());
		}
		else
		{
			currencyName->addFractional(amount);
			currencyName->addWhole(amount);
		}
	}
}

//Removes currency to the wallet class with currency functions
void Wallet::removeCurrency(Currency *currencyName, double amount)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (0 == walletList[i].getWholeParts && 0 == walletList[i].getFractionalParts)
		{
			throw (ExceptionWalletZero());
		}
		else
		{
			currencyName->addFractional(amount);
			currencyName->addWhole(amount);
		}
	}
}

//sets all whole and fractionalparts to 0.
void Wallet::zeroAllCurrency()
{
	dollar->empty();
	euro->empty();
	yen->empty();
	rupee->empty();
	yuan->empty();
}

//Checks if wallet is empty.
bool Wallet::walletIsEmpty()
{
	for (int i = 0; i < 5; i++)
	{
		if (0 == walletList[i].getWholeParts && 0 == walletList[i].getFractionalParts) {
			return true;
		}else
		return false;
	}
}


//Checks if currency is not zero
bool Wallet::isCurrencyNonZero(Currency *currencyName)
{
	if (0 != currencyName->getWholeParts && 0 != currencyName->getFractionalParts)
	{
		return true;
	}else
	return false;
}