#pragma once
#include "Currency.h"

class Yen : public Currency
{
public:
	Yen(int whole, int fractional) : Currency("Yen", "Yen", "Sen", "Sen", whole, fractional) {};
	~Yen();
};