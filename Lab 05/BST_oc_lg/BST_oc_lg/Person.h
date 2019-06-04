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

struct Person
{
public:
	std::string *name; //Format: "first last"
	std::string *birthday; //Format: "yyyy-mm-dd"

	Person(std::string*, std::string*);
	virtual ~Person();
};