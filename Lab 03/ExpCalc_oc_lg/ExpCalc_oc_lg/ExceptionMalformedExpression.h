#include <exception>

class ExceptionMalformedExpression : public std::exception
{
public:
	const char* what() const { return "Error: Malformed expression - allowed characters: +, -, *, /, %, (, )"; }
};