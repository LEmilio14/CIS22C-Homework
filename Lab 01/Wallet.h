#pragma once
#include<string>

class Wallet 
{
private:
	class dollar;
	class euro;
	class yen;
	class rupee;
	class yuan;
public:

	//CONSTRUCTORS
	Wallet();
	Wallet(double dollar, double euro, double yen, double rupee, double yuan);

	//FUNCTIONS
	int getNumbOfNonZeroCur();

	void addCurrency(std::string currencyName, double amount);
	void removeCurrency(std::string currencyName, double amount);
	void zeroAllCurrency();

	bool isEmpty();

	//OVERLOADS
	//class& operator[](const int index);

};