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

	myQueue.enqueue(six);
	myQueue.enqueue(five);
	myQueue.enqueue(four);
	myQueue.enqueue(three);
	myQueue.enqueue(two);
	myQueue.enqueue(one);

	myQueue.display();

	




	system("pause");
	return 0;
}