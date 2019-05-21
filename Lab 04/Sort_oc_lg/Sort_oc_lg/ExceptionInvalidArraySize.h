#include <exception>

class ExceptionInvalidArraySize : public std::exception
{
public:
	const char* what() const { return "Error: Invalid array size."; }
};