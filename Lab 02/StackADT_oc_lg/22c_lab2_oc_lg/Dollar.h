
#pragma once
#include "Currency.h"

class Dollar : public Currency
{
public:
	Dollar(int whole, int fractional) : Currency("USD", "Dollar", "Dollars", "Cent", "Cents", whole, fractional) {};
	~Dollar();
};