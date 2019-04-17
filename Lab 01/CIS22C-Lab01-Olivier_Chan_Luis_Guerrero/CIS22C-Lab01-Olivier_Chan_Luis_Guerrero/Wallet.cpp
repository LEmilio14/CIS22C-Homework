#include"Wallet.h"
#include"Currency.h"

Wallet::Wallet(double dol, double eu, double ye, double rup, double yu)
{

	dollar = new Currency("Dollar", "Dollars", "Cent", "Cents", static_cast<int>(numb), static_cast<int>(((int)numb % 100) * 100));
	euro = new Currency("Euro", "Euros", "Cent", "Cents", static_cast<int>(numb), static_cast<int>(((int)numb % 100) * 100));
	yen = new Currency("Yen", "Yen", "Sen", "Sen", static_cast<int>(numb), static_cast<int>(((int)numb % 100) * 100));
	rupee = new Currency("Rupee", "Rupees", "Paisa", "Paise", static_cast<int>(numb), static_cast<int>(((int)numb % 100) * 100));
	yuan = new Currency("Yuan", "Yuan", "Fen", "Fens", static_cast<int>(numb), static_cast<int>(((int)numb % 100) * 100));

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

void Wallet::addCurrency(std::string currencyName, double amount)
{
	int i;
	int wholeParts = wallet.getTotalWholeParts();


	for (i = 0; i < 5 ; i++)
	{
		if (currencyName = walletList[i])
		{

		}
	}
}