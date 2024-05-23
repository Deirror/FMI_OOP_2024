#include <iostream>
#include "Stack.h"

int main()
{
	Stack<int,10> stack;

	stack.push(1);
	stack.push(2);
	stack.push(2);
	stack.push(2);
	stack.pop();
	stack.push(3);
	stack.push(4);

	stack.pop();

	std::cout << stack.peek();

	return 0;
}