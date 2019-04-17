#pragma once
#include<string>
#include"Currency.h"
#include"Wallet.h"

class Wallet
{
private:
	Currency wallet;
	Currency walletList[5] = {Currency("Dollar", "Dollars", "Cent", "Cents", wallet.getWholeParts() , wallet.getFractionalParts()),
							Currency("Euro", "Euros", "Cent", "Cents", wallet.getWholeParts(),wallet.getFractionalParts()),
							Currency("Yen", "Yen", "Sen", "Sen", wallet.getWholeParts(),wallet.getFractionalParts()),
							Currency("Rupee", "Rupees", "Paisa", "Paise", wallet.getWholeParts(),wallet.getFractionalParts()),
							Currency("Yuan", "Yuan", "Fen", "Fens", wallet.getWholeParts(),wallet.getFractionalParts()) };
	Currency *dollar;
	Currency *euro;
	Currency *yen;
	Currency *rupee;
	Currency *yuan;
	double numb;
public:

	//CONSTRUCTORS
	Wallet(double dol, double eu, double ye, double rup, double yu);


	//FUNCTIONS
	int getNumbOfNonZeroCur();


	void addCurrency(std::string currencyName, double amount);
	void removeCurrency(std::string currencyName, double amount);
	void zeroAllCurrency();

	bool isEmpty();
	bool isCurrencyNonZero(std::string currencyName);

	//OVERLOADS
	Currency& operator[](const int index);

	Wallet(double & dol, double & eu, double & ye, double & rup, double & yu);

};