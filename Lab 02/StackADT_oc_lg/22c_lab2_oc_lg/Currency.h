/*
* Currency
*
* Notes:
* - Any operation (set, add, etc.) that would result in negative currency will throw an exception. The operation will not be performed.
* - Arithmetic operations can be performed between: [A] Currency and a number [B] Currency and Currency (same type)
* - Any operations involving two Currency objects must be between Currency objects of the same type (Dollars cannot be added or compared to Euros).
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
	std::string abbreviation; //USD, EUR, JPY, INR, CNY
	std::string currencyNote; //Dollar, Euro, Yen, Rupee, Yuan
	std::string currencyNotePlural; //Dollars, Euros, Yen, Rupees, Yuan
	std::string currencyCoin; //Cent, Cent, Sen, Paisa, Fen
	std::string currencyCoinPlural; //Cents, Cents, Sen, Paise, Fens
	int wholeParts;
	int fractionalParts;
public:
	//Constants
	static const int fractionsInWhole = 100;
	//Constructors
	Currency();
	Currency(std::string abbr, std::string note, std::string notePlural, std::string coin, std::string coinPlural, int whole, int fractional) : abbreviation(abbr), currencyNote(note), currencyNotePlural(notePlural), currencyCoin(coin), currencyCoinPlural(coinPlural), wholeParts(whole), fractionalParts(fractional) {};
	//Virtual destructor since Currency is a base class
	virtual ~Currency();
	//Helper functions
	void empty();
	bool isEmpty();
	bool isSameType(const Currency currency) const; //Checks whether all currency names match
	//Add functions: Add negative numbers to subtract. Adding 1.5 will add 1 whole and 50 fractions. Note that setting whole or fractional parts to negative values will throw an ExceptionCurrencyNegative.
	void addWhole(const double a);
	void addFractional(const int a);
	//Get & Set functions:
	//fooWhole and fooFractional only concern either whole or fractional values.
	//Ex. setWhole(3) sets wholeParts to 3 and leaves fractionalParts alone. getWhole() will return the value of wholeParts, ignoring fractionalParts entirely.
	//fooTotalWhole and fooTotalFractional concern both whole and fractional values at the same time.
	//Ex. setTotalWhole(1.5) sets wholeParts to 1 and fractional parts to 50. setTotalFractionalParts(150) is equivalent, sets wholeParts to 1 and fractional parts to 50.
	//Note that setting whole or fractional parts to negative values will throw an ExceptionCurrencyNegative.
	std::string getCurrencyAbbreviation() const;
	std::string getCurrencyNote() const;
	std::string getCurrencyNotePlural() const;
	std::string getCurrencyCoin() const;
	std::string getCurrencyCoinPlural() const;
	void setCurrencyAbbreviation(const std::string abbr);
	void setCurrencyNote(const std::string note);
	void setCurrencyNotePlural(const std::string notePlural);
	void setCurrencyCoin(const std::string coin);
	void setCurrencyCoinPlural(const std::string coinPlural);
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
	//Comparison Operator Overloads: ==, !=, <, >, <=, >= compare whole and fractional parts. Comparing currencies of different type (currency names) will throw an ExceptionCurrencyMismatch.
	friend bool operator==(const Currency& left, const Currency& right);
	friend bool operator!=(const Currency& left, const Currency& right);
	friend bool operator<(const Currency& left, const Currency& right);
	friend bool operator>(const Currency& left, const Currency& right);
	friend bool operator<=(const Currency& left, const Currency& right);
	friend bool operator>=(const Currency& left, const Currency& right);
	//I&O Stream Overloads: Input sets the currency to the input double, similar to setTotalWholeParts(). Output outputs the value of the currency, ex. "1 Dollar and 50 Cents", using the correct plurals.
	friend std::istream& operator>>(std::istream& is, Currency& currency);
	friend std::ostream& operator<<(std::ostream& os, const Currency& currency);
};