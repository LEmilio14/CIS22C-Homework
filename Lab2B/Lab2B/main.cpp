#include <iostream>
#include "List.h"
#include "Dollar.h"
#include "Queue.h"

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
	//Queue of currency objects
	cout << "Creating a queue of dollar currencies" << endl;
	Queue<Currency> myQueue;
	Currency* one = new Dollar(1,0);
	Currency* two = new Dollar(43, 5);
	Currency* three = new Dollar(11, 20);
	Currency* four = new Dollar(56, 23);
	Currency* five = new Dollar(45, 7);
	cout << "Enqueue the different values" << endl;
	myQueue.enqueue(*one);
	myQueue.enqueue(*two);
	myQueue.enqueue(*three);
	myQueue.enqueue(*four);
	myQueue.enqueue(*five);
	cout << "Getting the first and last element of the queue" << endl;
	cout << "Front element: "<< myQueue.getFront() << endl;
	cout << "Last element: " << myQueue.getRear() << endl;
	cout << "Dequeue" << endl;
	myQueue.dequeue();
	cout << "The new last element of the queue" << endl;
	cout << "Front element: " << myQueue.getFront() << endl;
	cout << "Last element: " << myQueue.getRear() << endl;

	system("pause");
	return 0;
}