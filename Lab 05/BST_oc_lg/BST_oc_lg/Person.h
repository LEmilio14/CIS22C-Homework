/********************************************************************************
************************************ BST ****************************************
*********************************************************************************
* This class stores the name and birthday of a person.
*****************
***** USAGE *****
*****************
*
*********************************************************************************/

#pragma once

#include <string>

class Person
{
private:
	std::string name; //Format: "first last"
	std::string birthday; //Format: "yyyy-mm-dd"
public:
	Person(std::string, std::string);
	virtual ~Person();

	void setName(std::string);
	void setBday(std::string);

	std::string getName();
	std::string getBda();
};