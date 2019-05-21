#include <exception>

class ExceptionInvalidArrayIndex : public std::exception
{
public:
	const char* what() const { return "Error: Invalid array index."; }
};