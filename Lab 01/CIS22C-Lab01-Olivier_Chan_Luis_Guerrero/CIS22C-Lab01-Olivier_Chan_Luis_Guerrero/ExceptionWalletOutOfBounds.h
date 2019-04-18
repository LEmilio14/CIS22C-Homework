#pragma once
#include <exception>

class ExceptionWalletOutOfBounds : public std::exception
{
public:
	const char* what() const { return "Error: Out of bounds."; }
};