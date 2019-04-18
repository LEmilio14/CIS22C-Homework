#pragma once
#include "Currency.h"

class Euro : public Currency
{
public:
	Euro(int whole, int fractional) : Currency("Euro", "Euros", "Cent", "Cents", whole, fractional) {};
	~Euro();
};