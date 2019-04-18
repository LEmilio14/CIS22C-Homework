#pragma once
#include "Currency.h"

class Yuan : public Currency
{
public:
	Yuan(int whole, int fractional) : Currency("Yuan", "Yuan", "Fen", "Fen", whole, fractional) {};
	~Yuan();
};