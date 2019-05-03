/*
CIS 22C
Lab 02: Implement a link-based Stack ADT to the Currency class.	
Group Members:
Oliver Chan Sion Moy
Luis Guerrero
*/

#include <iostream>
#include <string>
#include "List.h"
#include "Stack.h"
#include "Dollar.h"

using namespace std;

int main()
{
	//Demonstrate Lists with int and string
	List<int> intList;
	List<string> stringList;
	//Int List Creation
	cout << "Creating a list {1,2,3,4,5}" << endl;
	int i1 = 1;
	int i2 = 2;
	int i3 = 3;
	int i4 = 4;
	int i5 = 5;
	intList.insertLast(i1);
	intList.insertLast(i2);
	intList.insertLast(i3);
	intList.insertLast(i4);
	intList.insertLast(i5);
	cout << intList;
	//List Insertion
	cout << "Insert integer 6 into index 1" << endl;
	int i6 = 6;
	intList.insert(i6, 1);
	cout << intList;
	//List Removal
	cout << "Remove first element" << endl;
	intList.removeFirst();
	cout << intList;
	//List Removal
	cout << "Remove last element" << endl;
	intList.removeLast();
	cout << intList;
	//String List Creation
	cout << "Creating a list {\"Hello\",\"World\"}" << endl;
	string s1 = "Hello";
	string s2 = "World";
	stringList.insertLast(s1);
	stringList.insertLast(s2);
	cout << stringList;
	//List Search
	cout << "Finding second element" << endl;
	cout << stringList.getData(1) << endl;
	//List Count
	cout << "Finding count of elements" << endl;
	cout << stringList.getCount() << endl;
	//List Empty
	cout << "Empty the list" << endl;
	stringList.removeAll();
	cout << stringList;
	//Stack of Currency (Dollar) Creation
	cout << "Creating a stack of dollar currencies" << endl;
	Stack<Currency> stack;
	Currency* dol1 = new Dollar(1, 0);
	Currency* dol2 = new Dollar(2, 2);
	Currency* dol3 = new Dollar(123, 99);
	cout << "Push" << endl;
	stack.push(*dol1);
	stack.push(*dol2);
	stack.push(*dol3);
	cout << "Peek" << endl;
	cout << stack.peek() << endl;
	cout << "Pop" << endl;
	stack.pop();
	cout << "Peek" << endl;
	cout << stack.peek() << endl;
	cout << "Pop" << endl;
	stack.pop();
	cout << "Peek" << endl;
	cout << stack.peek() << endl;

	cin.get();
	delete dol1;
	delete dol2;
	delete dol3;
	return 0;
}