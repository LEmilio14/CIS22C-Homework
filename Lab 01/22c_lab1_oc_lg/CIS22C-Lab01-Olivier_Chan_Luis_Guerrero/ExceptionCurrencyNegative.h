#include <exception>

class ExceptionCurrencyNegative : public std::exception
{
public:
	const char* what() const { return "Error: Currency cannot be negative."; }
};