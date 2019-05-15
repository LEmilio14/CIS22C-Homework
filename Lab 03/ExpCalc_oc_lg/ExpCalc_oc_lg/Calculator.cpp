#include "Calculator.h"

/**
* splitString
*
* @brief Creates an array of substrings from a parent string, the substrings being tokens of the parent string seperated by spaces.
*
* @param str The parent string to generate substrings from.
*
* @return An array of substrings generated from the parent string.
*/

std::unique_ptr<std::string[]> Calculator::splitString(std::string str)
{
	int numberOfTokens = getNumberOfTokens(str);

	auto stringArray = std::make_unique<std::string[]>(numberOfTokens);

	size_t pos = 0;
	size_t start = 0;
	size_t end = 0;

	//While the end of the string hasn't been reached
	for (int i = 0; i < numberOfTokens; i++)
	{
		//Find the first non-space character from pos
		start = str.find_first_not_of(' ', pos);
		//Then find the end of the first non-space character
		end = str.find_first_of(' ', start);
		//Add the token to the array
		stringArray[i] = str.substr(start, end - start);
		//Move pos forward
		pos = end;
	}

	return stringArray;
}

/*
std::string Calculator::expressionToPostFix1(std::unique_ptr<std::string[]> &tokenArray, int tokenArraySize)
{
	Stack<std::string> expressionStack;
	//Stack<std::string> operatorStack;
	std::string result;
	//std::unique_ptr<std::string[]> expressionArray;
	//auto expressionArray = std::make_unique<std::string[]>(tokenArraySize);

		for (int i = 0; i < tokenArraySize; i++)
		{
			if (isOperand(tokenArray[i]))
			{
				result += tokenArray[i];
			}
			else if (isOperator(tokenArray[i]))
			{
				if (expressionStack.isEmpty() ||
					expressionStack.peek() == "(" ||
					getOperatorPrecedence(tokenArray[i]) > getOperatorPrecedence(expressionStack.peek()))
				{
					expressionStack.push(tokenArray[i]);
				}
				else
				{
					while (getOperatorPrecedence(tokenArray[i]) <= getOperatorPrecedence(expressionStack.peek()))
					{
						result += expressionStack.peek();
						//expressionStack.push(operatorStack.peek());
						expressionStack.pop();
					}
					expressionStack.push(tokenArray[i]);
				}
			}
			else if (tokenArray[i] == "(")
			{
				expressionStack.push(tokenArray[i]);
			}
			else if (tokenArray[i] == ")")
			{
				while (!expressionStack.isEmpty() && expressionStack.peek() != "(") {
					result += expressionStack.peek();
					expressionStack.pop();
				}
				expressionStack.pop();
			}
			else
			{
				throw ExceptionMalformedExpression();
			}
		}
		while (!expressionStack.isEmpty()) {
			result += expressionStack.peek();
			expressionStack.pop();
		}

	return result;
}
*/

/**
* expressionToPostFix
*
* @brief 
*/
std::unique_ptr<std::string[]> Calculator::expressionToPostFix(std::unique_ptr<std::string[]> tokenArray, int tokenArraySize)
{
	Stack<std::string> expressionStack;
	Stack<std::string> operatorStack;
	std::unique_ptr<std::string[]> expressionArray;
	auto expressionArray = std::make_unique<std::string[]>(tokenArraySize);

	for (int i = 0; i < tokenArraySize; i++)
	{
		std::cout << i << std::endl;
		std::cout << operatorStack;
		//Push operands immediately
		if (isOperand(tokenArray[i]))
		{
			expressionStack.push(tokenArray[i]);
		}
		else if (isOperator(tokenArray[i]))
		{
			//If operator is ")", pop operators until "("
			if (tokenArray[i] == ")")
			{
				while (operatorStack.peek() != "(")
				{
					expressionStack.push(operatorStack.peek());
					operatorStack.pop();
				}
				operatorStack.pop();
			}
			//If operator stack is empty, is "(", or is lower precedence, push new operator
			else if (operatorStack.count() == 0 ||
				operatorStack.peek() == "(" ||
				getOperatorPrecedence(tokenArray[i]) > getOperatorPrecedence(operatorStack.peek()))
			{
				operatorStack.push(tokenArray[i]);
			}
			//If operator stack is equal or higher precedence, pop operators until it isn't, then push new operator
			else if (getOperatorPrecedence(tokenArray[i]) <= getOperatorPrecedence(operatorStack.peek()))
			{
				while (getOperatorPrecedence(tokenArray[i]) <= getOperatorPrecedence(operatorStack.peek()) && operatorStack.count() > 0)
				{
					expressionStack.push(operatorStack.peek());
					operatorStack.pop();
				}
				operatorStack.push(tokenArray[i]);
			}
		}
		else
		{
			throw ExceptionMalformedExpression();
		}
	}

	//Pop remaining operators
	while (operatorStack.count() > 0)
	{
		expressionStack.push(operatorStack.peek());
		operatorStack.pop();
	}

	while (expressionStack.count() > 0)
	{
		std::cout << expressionStack.peek() << std::endl;
		expressionStack.pop();
	}

	return;
}

/**
* getNumberOfTokens
*
* @brief Returns the number of tokens in a given string, delimited by any number of spaces.
*
* @param str The string to count substrings from.
*
* @return The number of tokens in the string.
*/

int Calculator::getNumberOfTokens(std::string str)
{
	int numberOfTokens = 0;
	size_t pos = 0;

	//While the end of the string hasn't been reached
	while (pos != std::string::npos)
	{
		//Find the first non-space character
		pos = str.find_first_not_of(' ', pos);
		//Then move to the end of that non-space character
		pos = str.find_first_of(' ', pos);
		//Add a token
		numberOfTokens++;
	}

	return numberOfTokens;
}

/**
* isOperator
*
* @brief Checks whether a given string is a valid operator, allowed characters: +, -, *, /, %, (, )
*
* @param str The string to check.
*
* @return Whether the string is a valid operator or not.
*/

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

/**
* isOperand
*
* @brief Checks whether a given string is a valid operand, allowed characters: 1, 2, 3, 4, 5, 6, 7, 8, 9, 0
*
* @param str The string to check.
*
* @return Whether the string is a valid operand or not.
*/

bool Calculator::isOperand(std::string str)
{
	if (str.size() == 0)
	{
		return false;
	}
	
	for (size_t i = 0; i < str.size(); i++)
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

/**
* getOperatorPrecedence
*
* @brief 
*/

int Calculator::getOperatorPrecedence(std::string str)
{
	if (str == "+" || str == "-")
	{
		return 1;
	}
	else if (str == "*" || str == "/" || str == "%")
	{
		return 2;
	}
	else if (str == "(" || str == ")")
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

/**
* reverseString
*
* @brief Reverse the string that was built from spliString function
*
* @param the array string and the size
*
* @return None.
*/
void Calculator::reverseString(std::unique_ptr<std::string[]> &stringReverse, int size)
{
	int len = size / 2;
	std::string temp;
	if (size % 2 == 0)
	{
		for (int i = 0; i < len ; i++)
		{
			temp = stringReverse[size - 1 - i];
			stringReverse[size - 1 - i] = stringReverse[i];
			stringReverse[i] = temp;
		}
	}

}

Calculator::Calculator()
{

}

Calculator::~Calculator()
{

}