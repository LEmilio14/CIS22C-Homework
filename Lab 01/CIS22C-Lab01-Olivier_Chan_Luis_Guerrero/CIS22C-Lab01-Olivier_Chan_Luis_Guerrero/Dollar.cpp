#include "Dollar.h"

Dollar::Dollar(int whole, int fractional)
{
	setWholeParts(whole);
	setFractionalParts(fractional);
}

Dollar::~Dollar()
{

}