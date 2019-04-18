#pragma once
#include "Currency.h"

class Dollar : public Currency
{
public:
	Dollar(int whole, int fractional) : Currency("Dollar", "Dollars", "Cent", "Cents", whole, fractional) {};
	~Dollar();
};