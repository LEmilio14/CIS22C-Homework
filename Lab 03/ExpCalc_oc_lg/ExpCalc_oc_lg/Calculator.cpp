#include "Calculator.h"

std::unique_ptr<std::string[]> Calculator::splitString(std::string str)
{
	int numberOfTokens = getNumberOfTokens(str);

	auto stringArray = std::make_unique<std::string[]>(numberOfTokens);

	//Start after any leading spaces
	size_t start = str.find_first_not_of(' ');
	size_t end = start;
	
	for (int i = 0; i < str.size(); i++)
	{

	}

	for (int i = 0; i < str.size(); i++)
	{
		
	}

	return stringArray;
}

int Calculator::getNumberOfTokens(std::string str)
{
	int numberOfTokens = 0;
	bool space = true;
	
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			space = true;
		}
		else
		{
			if (space == true)
			{
				numberOfTokens++;
				space = false;
			}
		}
	}

	return numberOfTokens;
}

bool Calculator::isOperator(std::string str)
{
	if (str == "+" ||
		str == "-" ||
		str == "*" || 
		str == "/" ||
		str == "%" ||
		str == "(" ||
		str == ")")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Calculator::isOperand(std::string str)
{
	if (str.size() == 0)
	{
		return false;
	}
	
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != '1' &&
			str[i] != '2' &&
			str[i] != '3' &&
			str[i] != '4' &&
			str[i] != '5' &&
			str[i] != '6' &&
			str[i] != '7' &&
			str[i] != '8' &&
			str[i] != '9' &&
			str[i] != '0')
		{
			return false;
		}
	}

	return true;
}

Calculator::Calculator()
{

}

Calculator::~Calculator()
{

}