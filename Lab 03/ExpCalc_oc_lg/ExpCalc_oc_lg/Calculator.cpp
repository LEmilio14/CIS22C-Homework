#include "Calculator.h"

/**
* splitString
*
* @brief Creates an array of substrings from a parent string, the substrings being tokens of the parent string separated by spaces.
*
* @param str The parent string to generate substrings from.
*
* @return An array of substrings generated from the parent string.
*/

std::string* Calculator::splitString(std::string str)
{
	int numberOfTokens = getNumberOfTokens(str);

	std::string* stringArray = new std::string[numberOfTokens];

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

/**
* infixToPostfix
*
* @brief Converts a string infix expression into an array of string tokens (operands and operators) in postfix order. The array is terminated with the string "\0".
*
* @param infix A string infix expression, with all seperate operands and operators seperated by spaces.
*
* @return An array of tokens in postfix order. The array is terminated with the string "\0".
*/

std::string* Calculator::infixToPostfix(std::string infix)
{
	Stack<std::string> operatorStack;
	Queue<std::string> expressionQueue;
	int expressionQueueSize = 0;

	std::string* tokenArray = splitString(infix); //Convert the expression string into an array of tokens
	int tokenArraySize = getNumberOfTokens(infix);

	for (int i = 0; i < tokenArraySize; i++)
	{
		//If token is an operand
		if (isOperand(tokenArray[i]))
		{
			//Enqueue operands immediately
			expressionQueue.enqueue(tokenArray[i]);
			expressionQueueSize++;
		}
		//If token is an operator
		else if (isOperator(tokenArray[i]))
		{
			//While the stack isn't empty and the top of the stack is higher or equal precedence (exception: parentheses), pop and enqueue operators from the stack
			while (!operatorStack.isEmpty() && operatorStack.peek() != "(" && operatorStack.peek() != ")" && getOperatorPrecedence(operatorStack.peek()) >= getOperatorPrecedence(tokenArray[i]))
			{
				expressionQueue.enqueue(operatorStack.pop());
				expressionQueueSize++;
			}

			//If operator is ")", pop and enqueue operators until "("
			if (!operatorStack.isEmpty() && tokenArray[i] == ")")
			{
				while (!operatorStack.isEmpty())
				{
					if (operatorStack.peek() == "(")
					{
						operatorStack.pop();
						break;
					}
					else
					{
						expressionQueue.enqueue(operatorStack.pop());
						expressionQueueSize++;
					}
				}
			}
			else
			{
				operatorStack.push(tokenArray[i]);
			}
		}
		else
		{
			throw ExceptionMalformedExpression();
		}
	}

	//Pop remaining operators
	while (!operatorStack.isEmpty())
	{
		expressionQueue.enqueue(operatorStack.pop());
		expressionQueueSize++;
	}

	//Create the expression array with one extra space so a terminator can be added
	std::string* expressionArray = new std::string[expressionQueueSize + 1];

	//Populate the expression array with the queue
	for (int i = 0; i < expressionQueueSize; i++)
	{
		expressionArray[i] = expressionQueue.dequeue();
	}

	//Delete the token array since the queue and stack are no longer needed
	delete [] tokenArray;

	//Set the last element of the array as a terminator
	expressionArray[expressionQueueSize] = "\0";

	return expressionArray;
}

/**
* infixToPrefix
*
* @brief
*
* @param
*
* @return
*/

std::unique_ptr<std::string[]> Calculator::infixToPrefix(std::unique_ptr<std::string[]> &tokenArray, int arraySize)
{
	Calculator c;
	Stack<std::string> operatorStack;
	Queue<std::string> operandQueue;
	std::unique_ptr<std::string[]> expressionArray;

	for (int i = 0; i < arraySize; i++)
	{
		if (c.isOperand(tokenArray[i]))
		{
			operandQueue.enqueue(tokenArray[i]);
		}
		else if (c.isOperator(tokenArray[i]))
		{
			if (operatorStack.getCount() == 0 || c.getOperatorPrecedence(tokenArray[i]) >= c.getOperatorPrecedence(operatorStack.peek())
				|| tokenArray[i] == "(")
			{
				operatorStack.push(tokenArray[i]);
			}
			else if (tokenArray[i] == ")")
			{
				while (operatorStack.peek() != "(")
				{
					operandQueue.enqueue(operatorStack.peek());
					operatorStack.pop();
				}
				operatorStack.pop();
			}
			else if (c.getOperatorPrecedence(tokenArray[i]) < c.getOperatorPrecedence(operatorStack.peek()))
			{
				while (c.getOperatorPrecedence(operatorStack.peek()) < c.getOperatorPrecedence(tokenArray[i]) || operatorStack.getCount() >= 0)
				{
					operandQueue.enqueue(operatorStack.peek());
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
	while (operatorStack.getCount() >= 0)
	{
		operandQueue.enqueue(operatorStack.peek());
		operatorStack.pop();
	}

	while (operandQueue.isEmpty())
	{
		std::cout << operandQueue.getFront() << std::endl;
		operandQueue.dequeue();
	}

	for (int j = 0; j > operandQueue.getCount(); j++)
	{
		expressionArray[j] = operandQueue.getFront();
	}
	
	return expressionArray;
}

int Calculator::resolvePrefix(Stack<std::string> prefixStack, Queue<std::string> prefixQueue)
{

	return 0;
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
* arrayToString
*
* @brief Convert an expression array into a string representation.
*
* @param array The expression array to convert.
*
* @return The string representation of the expression array.
*/

std::string arrayToString(std::unique_ptr<std::string[]>& expressionArray)
{
	std::string expressionString = std::string();

	int i = 0;
	while (expressionArray[i] != "\0")
	{
		expressionString.append(expressionArray[i]);
		i++;
	}

	return expressionString;
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

std::string* Calculator::reverseString(std::string expressionString)
{
	std::string *stringReverse = splitString(expressionString);
	int len = getNumberOfTokens(expressionString);
	std::string temp;
	for (int i = 0; i < len / 2 ; i++)
	{
		temp = stringReverse[len - 1 - i];
		stringReverse[len - 1 - i] = stringReverse[i];
		stringReverse[i] = temp;
		if (stringReverse[i] == "(")
		{
			stringReverse[i] = ")";
		}
		else if (stringReverse[i] == ")")
		{
			stringReverse[i] = "(";
		}
	}
	return stringReverse;
}

Calculator::Calculator()
{

}

Calculator::~Calculator()
{

}