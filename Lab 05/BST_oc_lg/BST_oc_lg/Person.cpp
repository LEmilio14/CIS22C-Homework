#include "Person.h"

Person::Person(std::string n, std::string b) : name(n), birthday(b)
{

}

Person::~Person()
{

}

void Person::setName(std::string n)
{
	name = n;
}

void Person::setBday(std::string b)
{
	birthday = b;
}

std::string Person::getName()
{
	return name;
}

std::string Person::getBda()
{
	return birthday;
}
