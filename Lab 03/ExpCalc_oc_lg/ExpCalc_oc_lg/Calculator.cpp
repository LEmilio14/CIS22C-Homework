#include "Calculator.h"

std::string Calculator::getNext(std::string str)
{
	int beg = 0;
	int end = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			return str.substr(beg, end);
		}
		else
		{
			end++;
		}
	}

	return str.substr(beg, end);
}

Calculator::Calculator()
{

}

Calculator::~Calculator()
{

}