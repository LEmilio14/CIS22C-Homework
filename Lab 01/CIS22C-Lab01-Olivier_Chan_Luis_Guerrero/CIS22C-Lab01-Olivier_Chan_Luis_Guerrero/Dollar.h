#pragma once
#include "Currency.h"

class Dollar : public Currency
{
public:
	Dollar(int whole, int fractional) : Currency("Dollar", whole, fractional) {}
	//Currency(std::string cNote, std::string cNotePlural, std::string cCoin, std::string cCoinPlural, int whole, int fractional)
		//:currencyNote(cNote), currencyNotePlural(cNotePlural), currencyCoin(cCoin), currencyCoinPlural(cCoinPlural), wholeParts(whole), fractionalParts(fractional) {}
	~Dollar();
};