#include "Currency.h"

Currency::Currency()
{

}

void Currency::empty()
{
	wholeParts = 0;
	fractionalParts = 0;
}

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

void Currency::addWhole(const double a)
{
	//Cast to truncate any extra decimals
	addFractional(static_cast<int>(a * Currency::fractionsInWhole));
}

void Currency::addFractional(const int a)
{
	int totalFractionalParts = getTotalFractionalParts() + a;
	int quotient = totalFractionalParts / Currency::fractionsInWhole;
	int remainder = totalFractionalParts % Currency::fractionsInWhole;

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

std::string Currency::getCurrencyNote() const
{
	return currencyNote;
}

std::string Currency::getCurrencyNotePlural() const
{
	return currencyNotePlural;
}

std::string Currency::getCurrencyCoin() const
{
	return currencyCoin;
}

std::string Currency::getCurrencyCoinPlural() const
{
	return currencyCoinPlural;
}

int Currency::getWholeParts() const
{
	return wholeParts;
}

int Currency::getFractionalParts() const
{
	return fractionalParts;
}

double Currency::getTotalWholeParts() const
{
	return wholeParts + (static_cast<double>(fractionalParts) / Currency::fractionsInWhole);
}

int Currency::getTotalFractionalParts() const
{
	return (wholeParts * Currency::fractionsInWhole) + fractionalParts;
}

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

	if (temp != currency)
	{
		throw(ExceptionCurrencyMismatch());
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

	if (temp != currency)
	{
		throw(ExceptionCurrencyMismatch());
	}
	else
	{
		temp -= currency.getTotalWholeParts();
		return temp;
	}
}

Currency& Currency::operator+=(const Currency& currency)
{
	if (*this != currency)
	{
		throw(ExceptionCurrencyMismatch());
	}
	else
	{
		*this += currency.getTotalWholeParts();
		return *this;
	}
}

Currency& Currency::operator-=(const Currency& currency)
{
	if (*this != currency)
	{
		throw(ExceptionCurrencyMismatch());
	}
	else
	{
		*this -= currency.getTotalWholeParts();
		return *this;
	}
}

bool operator==(const Currency& left, const Currency& right)
{
	if (left.currencyNote == right.currencyNote &&
		left.currencyNotePlural == right.currencyNotePlural &&
		left.currencyCoin == right.currencyCoin &&
		left.currencyCoinPlural == right.currencyCoinPlural)
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
	if (left.currencyNote != right.currencyNote ||
		left.currencyNotePlural != right.currencyNotePlural ||
		left.currencyCoin != right.currencyCoin ||
		left.currencyCoinPlural != right.currencyCoinPlural)
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
	if (left != right)
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
	if (left != right)
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
	if (left != right)
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
	if (left != right)
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