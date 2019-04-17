/*
* Currency
*
* Notes:
* - Any operation (set, add, etc.) that would result in negative currency will throw an exception. The operation will not be performed.
* - Arithmetic operations can be performed between: [A] Currency and a number [B] Currency and Currency (same type)
* - Operations involving two Currency objects must be between two Currency objects of the same type (Dollars cannot be compared to Euros).
*		An operation between two Currency objects of different types will throw an exception.
*
* Assumptions:
* - 1 whole part = 100 fractional parts, conversely 1 fractional part = 0.01 whole parts
* - Ultimately, whole and fractional parts are always integers (while there may be decimals involved inside functions, in the end whole and fractional parts should always end up as integers)
* - Whole and fractional parts can never be negative
*/

#pragma once

#include <string>
#include "ExceptionCurrencyMismatch.h"
#include "ExceptionCurrencyNegative.h"

class Currency
{
protected:
	std::string currencyNote; //Dollar, Euro, Yen, Rupee, Yuan
	std::string currencyNotePlural; //Dollars, Euros, Yen, Rupees, Yuan
	std::string currencyCoin; //Cent, Cent, Sen, Paisa, Fen
	std::string currencyCoinPlural; //Cents, Cents, Sen, Paise, Fens
	int wholeParts;
	int fractionalParts;
public:
	//Constants
	static const int fractionsInWhole = 100;
	//Constructor
	Currency();
	//Virtual destructor since Currency is a base class
	virtual ~Currency();
	//Helper functions
	void empty();
	bool isEmpty();
	//Add functions: Add negative numbers to subtract. Note that setting whole or fractional parts to negative values will throw an exception.
	void addWhole(const double a);
	void addFractional(const int a);
	//Get & Set functions: Note that setting whole or fractional parts to negative values will throw an exception.
	std::string getCurrencyNote() const;
	std::string getCurrencyNotePlural() const;
	std::string getCurrencyCoin() const;
	std::string getCurrencyCoinPlural() const;
	int getWholeParts() const;
	int getFractionalParts() const;
	double getTotalWholeParts() const;
	int getTotalFractionalParts() const;
	void setWholeParts(const int whole);
	void setFractionalParts(const int fractional);
	void setTotalFractionalParts(const int totalFractional);
	void setTotalWholeParts(const double totalWhole);
	// Arithmetic Operator Overloads: Arithmetic is performed as is in the real world - Adding 1.5 adds 1 to wholeParts and 50 to fractionalParts
	Currency operator+(const double a) const;
	Currency operator-(const double a) const;
	Currency& operator+=(const double a);
	Currency& operator-=(const double a);
	Currency operator+(const Currency& currency) const;
	Currency operator-(const Currency& currency) const;
	Currency& operator+=(const Currency& currency);
	Currency& operator-=(const Currency& currency);
	//Comparison Operator Overloads: ==, != compare types (currency names). <, >, <=, >= compare whole and fractional parts.
	friend bool operator==(const Currency& left, const Currency& right);
	friend bool operator!=(const Currency& left, const Currency& right);
	friend bool operator<(const Currency& left, const Currency& right);
	friend bool operator>(const Currency& left, const Currency& right);
	friend bool operator<=(const Currency& left, const Currency& right);
	friend bool operator>=(const Currency& left, const Currency& right);
	//I&O Stream Overloads: Input sets the currency to the input double. Output outputs the value of the currency, ex. "1 Dollar and 50 Cents", using the correct plurals.
	friend std::istream& operator>>(std::istream& is, Currency& currency);
	friend std::ostream& operator<<(std::ostream& os, const Currency& currency);
};