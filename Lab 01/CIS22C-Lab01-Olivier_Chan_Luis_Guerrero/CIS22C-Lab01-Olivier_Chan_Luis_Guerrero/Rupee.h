#pragma once
#include "Currency.h"

class Rupee : public Currency
{
public:
	Rupee(int whole, int fractional) : Currency("INR", "Rupee", "Rupees", "Paisa", "Paise", whole, fractional) {};
	~Rupee();
};