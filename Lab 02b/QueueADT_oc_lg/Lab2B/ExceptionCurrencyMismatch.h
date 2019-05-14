#include <exception>

class ExceptionCurrencyMismatch : public std::exception
{
public:
	const char* what() const { return "Error: Currency types do not match."; }
};