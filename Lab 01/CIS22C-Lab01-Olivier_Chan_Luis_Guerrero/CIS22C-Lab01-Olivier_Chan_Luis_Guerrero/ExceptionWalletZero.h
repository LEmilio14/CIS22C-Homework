#pragma once
#include <exception>

class ExceptionWalletZero : public std::exception
{
public:
	const char* what() const { return "Error: Currency is already empty."; }
};