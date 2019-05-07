#include<iostream>
#include"List.h"
#include"Node.h"
#include"Queue.h"

using namespace std;

int main()
{
	
	Queue<int> myQueue;
	int one = 1;
	int two = 2;
	int three = 3;
	int four = 4;
	int five = 5;
	int six = 6;

	myQueue.enqueue(one);
	myQueue.enqueue(two);
	myQueue.enqueue(three);
	myQueue.enqueue(four);
	myQueue.enqueue(five);
	myQueue.enqueue(six);

	cout << myQueue.front() << endl;
	cout << myQueue.rear() << endl;

	myQueue.display1();

	




	system("pause");
	return 0;
}