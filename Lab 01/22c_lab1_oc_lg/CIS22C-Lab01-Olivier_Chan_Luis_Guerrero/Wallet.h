#pragma once
#include <string>
#include "Currency.h"
#include "ExceptionWalletZero.h"

class Wallet
{
private:
	Currency* dollar; //Index = 0, Abbreviation: USD
	Currency* euro; //Index = 1, Abbreviation: EUR
	Currency* yen; //Index = 2, Abbreviation: JPY
	Currency* rupee; //Index = 3, Abbreviation: INR
	Currency* yuan; //Index = 4, Abbreviation: CNY
public:
	//CONSTRUCTORS
	Wallet(); //Equal to Wallet(0, 0, 0, 0, 0)
	Wallet(double dol, double eu, double ye, double ru, double yu);
	~Wallet();
	
	//FUNCTIONS
	int getNumZeroCurrency();
	int getNumNonZeroCurrency();
	void emptyCurrency(int index);
	void emptyCurrency(std::string abbr);
	void emptyAllCurrency();
	bool isCurrencyEmpty(int index);
	bool isCurrencyEmpty(std::string abbr);

	void addCurrency(int index, double amount);
	void addCurrency(int index, int whole = 0, int fractional = 0);
	void addCurrency(std::string abbr, double amount);
	void addCurrency(std::string abbr, int whole = 0, int fractional = 0);
	void removeCurrency(int index, double amount);
	void removeCurrency(int index, int whole = 0, int fractional = 0);
	void removeCurrency(std::string abbr, double amount);
	void removeCurrency(std::string abbr, int whole = 0, int fractional = 0);
	
	bool isWalletEmpty();
	
	//OVERLOADS
	Currency& operator[](const int index); //{dollar, euro, yen, rupee, yuan}
};