#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int> q;

	for (int i = 1; i <= 3; i++)
	{
		q.push(i);
    }

	q.pop();
	q.pop();
	q.pop();
	//std::cout << q.peek();//
	q.push(9 + 1);
	q.push(10);
	q.push(11);
	q.push(12);
	q.pop();
	q.print();

	return 0;
}