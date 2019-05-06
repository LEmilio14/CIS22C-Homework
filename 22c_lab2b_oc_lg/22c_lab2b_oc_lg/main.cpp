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

	myQueue.enqueue(one);
	myQueue.enqueue(two);
	myQueue.enqueue(three);

	cout << myQueue ;




	system("pause");
	return 0;
}