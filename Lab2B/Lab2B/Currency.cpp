#include "Currency.h"

Currency::Currency()
{
	abbreviation = "";
	currencyNote = "";
	currencyNotePlural = "";
	currencyCoin = "";
	currencyCoinPlural = "";
	int wholeParts = 0;
	int fractionalParts = 0;
}
/*
Empties any currency that the user specifies.
@pre The currency that the user wants to empty.
@post Makes whole parts 0 and fractional parts 0.
@return None.
*/
void Currency::empty()
{
	wholeParts = 0;
	fractionalParts = 0;
}

/*
Checks if a currency is 0.
@pre The currency that the user wants to check.
@post Checks if whole parts and fractional parts are 0.
@return True if both are 0, False if they are not zero.
*/
bool Currency::isEmpty()
{
	if (wholeParts == 0 && fractionalParts == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Checks if the currency enter is of the same type
@pre The currency that the user wants to check.
@post Checks if the note and the coin are the same.
@return True if they are the same, False if they are not.
*/
bool Currency::isSameType(const Currency currency) const
{
	if (currencyNote == currency.currencyNote &&
		currencyNotePlural == currency.currencyNotePlural &&
		currencyCoin == currency.currencyCoin &&
		currencyCoinPlural == currency.currencyCoinPlural)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Adds the whole parts of the number typed by the user.
@pre Const double.
@post Adds the integer to the whole parts.
@return N/A.
*/
void Currency::addWhole(const double a)
{
	//Cast to truncate any extra decimals
	addFractional(static_cast<int>(a * Currency::fractionsInWhole));
}

/*
Adds integers to the fractional parts.
@pre Const int.
@post Checks if currency can be negative / adds the integer to the fractional part.
@return N/A.
*/
void Currency::addFractional(const int a)
{
	int totalFractionalParts = getTotalFractionalParts() + a;
	int quotient = totalFractionalParts / Currency::fractionsInWhole;
	int remainder = totalFractionalParts % Currency::fractionsInWhole;

	//added a < 0
	if (quotient < 0 || remainder < 0)
	{
		throw (ExceptionCurrencyNegative());
	}
	else
	{
		wholeParts = quotient;
		fractionalParts = remainder;
	}
}

/*
Gets the crrency abbreviation.
@pre None.
@post None.
@return abbreviation of the currency.
*/
std::string Currency::getCurrencyAbbreviation() const
{
	return abbreviation;
}

/*
Gets the currency name.
@pre None.
@post None.
@return Currency note.
*/
std::string Currency::getCurrencyNote() const
{
	return currencyNote;
}

/*
Gets the currency plural name.
@pre None.
@post None.
@return Currency plural note.
*/
std::string Currency::getCurrencyNotePlural() const
{
	return currencyNotePlural;
}

/*
Gets the currency coin name.
@pre None.
@post None.
@return Currency coin name.
*/
std::string Currency::getCurrencyCoin() const
{
	return currencyCoin;
}

/*
Gets the currency plural coin name.
@pre None.
@post None.
@return Currency plural coin name.
*/
std::string Currency::getCurrencyCoinPlural() const
{
	return currencyCoinPlural;
}

/*
Sets Abbreviation.
@pre The string abbreviation of the currency type.
@post sets that currency abbreviation to the name of currency.
@return N/A.
*/
void Currency::setCurrencyAbbreviation(const std::string abbr)
{
	abbreviation = abbr;
}

/*
Sets Currency note.
@pre The string note of the currency type.
@post Sets that currency note to the name of currency.
@return N/A.
*/
void Currency::setCurrencyNote(const std::string note)
{
	currencyNote = note;
}

/*
Sets plural note of the currency.
@pre The string plural note of the currency type.
@post Sets that currency plural note to the name of currency.
@return N/A.
*/
void Currency::setCurrencyNotePlural(const std::string notePlural)
{
	currencyNotePlural = notePlural;
}

/*
Sets the coin of the currency.
@pre The string coin of the currency type.
@post Sets that currency coin to the currency.
@return N/A.
*/
void Currency::setCurrencyCoin(const std::string coin)
{
	currencyCoin = coin;
}

/*
Sets the plural coin of the currency.
@pre The string plural coin of the currency type.
@post Sets that currency plural coin to the currency.
@return N/A.
*/
void Currency::setCurrencyCoinPlural(const std::string coinPlural)
{
	currencyNote = coinPlural;
}

/*
Gets the whole parts of any currency.
@pre None.
@post None.
@return Whole parts.
*/
int Currency::getWholeParts() const
{
	return wholeParts;
}

/*
Gets the fractional parts of any currency.
@pre None.
@post None.
@return Fractional parts.
*/
int Currency::getFractionalParts() const
{
	return fractionalParts;
}

/*
Gets the total whole parts of any currency.
@pre None.
@post None.
@return Whole parts plus fracrional parts.
*/
double Currency::getTotalWholeParts() const
{
	return wholeParts + (static_cast<double>(fractionalParts) / Currency::fractionsInWhole);
}

/*
Gets the total fractional parts of any currency.
@pre None.
@post None.
@return Total Fractional Parts.
*/
int Currency::getTotalFractionalParts() const
{
	return (wholeParts * Currency::fractionsInWhole) + fractionalParts;
}

/*
Sets the whole parts of any currency.
@pre Const whole integer.
@post Checks if whole part enter is negative / sets whole part.
@return N/A.
*/
void Currency::setWholeParts(const int whole)
{
	if (whole < 0)
	{
		throw (ExceptionCurrencyNegative());
	}
	else
	{
		wholeParts = whole;
	}
}

/*
Sets fractional parts of any currency.
@pre const fractional integer.
@post checks if fractional part is zero / sets the fractional part for the currency.
@return N/A.
*/
void Currency::setFractionalParts(const int fractional)
{
	if (fractional < 0)
	{
		throw (ExceptionCurrencyNegative());
	}
	else
	{
		fractionalParts = fractional;
	}
}

/*
Sets the whole parts of any currency.
@pre const total fractional integer.
@post checks if the inetegr entered is negative / sets the fractional part entered.
@return Whole parts.
*/
void Currency::setTotalFractionalParts(const int totalFractional)
{
	if (totalFractional < 0)
	{
		throw (ExceptionCurrencyNegative());
	}
	else
	{
		int quotient = totalFractional / Currency::fractionsInWhole;
		int remainder = totalFractional % Currency::fractionsInWhole;

		wholeParts = quotient;
		fractionalParts = remainder;
	}
}

void Currency::setTotalWholeParts(const double totalWhole)
{
	if (totalWhole < 0)
	{
		throw (ExceptionCurrencyNegative());
	}
	else
	{
		wholeParts = static_cast<int>(totalWhole);
		fractionalParts = static_cast<int>((totalWhole - wholeParts) * Currency::fractionsInWhole);
	}
}

Currency Currency::operator+(const double a) const
{
	Currency temp = *this;

	temp.addWhole(a);

	return temp;
}

Currency Currency::operator-(const double a) const
{
	Currency temp = *this;

	temp.addWhole(-a);

	return temp;
}

Currency& Currency::operator+=(const double a)
{
	this->addWhole(a);

	return *this;
}

Currency& Currency::operator-=(const double a)
{
	this->addWhole(-a);

	return *this;
}

Currency Currency::operator+(const Currency& currency) const
{
	Currency temp = *this;

	if (!temp.isSameType(currency))
	{
		throw (ExceptionCurrencyMismatch());
	}
	else
	{
		temp += currency.getTotalWholeParts();
		return temp;
	}
}

Currency Currency::operator-(const Currency& currency) const
{
	Currency temp = *this;

	if (!temp.isSameType(currency))
	{
		throw (ExceptionCurrencyMismatch());
	}
	else
	{
		temp -= currency.getTotalWholeParts();
		return temp;
	}
}

Currency& Currency::operator+=(const Currency& currency)
{
	if (!this->isSameType(currency))
	{
		throw (ExceptionCurrencyMismatch());
	}
	else
	{
		*this += currency.getTotalWholeParts();
		return *this;
	}
}

Currency& Currency::operator-=(const Currency& currency)
{
	if (!this->isSameType(currency))
	{
		throw (ExceptionCurrencyMismatch());
	}
	else
	{
		*this -= currency.getTotalWholeParts();
		return *this;
	}
}

bool operator==(const Currency& left, const Currency& right)
{
	if (!left.isSameType(right))
	{
		throw (ExceptionCurrencyMismatch());
	}

	if (left.getTotalFractionalParts() == right.getTotalFractionalParts())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const Currency& left, const Currency& right)
{
	if (!left.isSameType(right))
	{
		throw (ExceptionCurrencyMismatch());
	}

	if (left.getTotalFractionalParts() != right.getTotalFractionalParts())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<(const Currency& left, const Currency& right)
{
	if (!left.isSameType(right))
	{
		throw (ExceptionCurrencyMismatch());
	}

	if (left.getTotalFractionalParts() < right.getTotalFractionalParts())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>(const Currency& left, const Currency& right)
{
	if (!left.isSameType(right))
	{
		throw (ExceptionCurrencyMismatch());
	}

	if (left.getTotalFractionalParts() > right.getTotalFractionalParts())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<=(const Currency& left, const Currency& right)
{
	if (!left.isSameType(right))
	{
		throw (ExceptionCurrencyMismatch());
	}

	if (left.getTotalFractionalParts() <= right.getTotalFractionalParts())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>=(const Currency& left, const Currency& right)
{
	if (!left.isSameType(right))
	{
		throw (ExceptionCurrencyMismatch());
	}

	if (left.getTotalFractionalParts() >= right.getTotalFractionalParts())
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::istream& operator>>(std::istream& is, Currency& currency)
{
	double input;

	is >> input;

	currency.setTotalWholeParts(input);

	return is;
}

std::ostream& operator<<(std::ostream& os, const Currency& currency)
{
	std::string note = (currency.wholeParts == 1 ? currency.currencyNote : currency.currencyNotePlural);
	std::string coin = (currency.fractionalParts == 1 ? currency.currencyCoin : currency.currencyCoinPlural);

	os << currency.wholeParts << " " << note << " and " << currency.fractionalParts << " " << coin;

	return os;
}

Currency::~Currency()
{

}