#include <iostream>
#include "Queue.h"

int main() 
{
    Queue<int> q;

    int a = 3;

    q.push(std::move(a));

    q.push(5);

    q.push(10);

    std::cout << q.peek();
    q.pop();
   
    std::cout << q.peek();
    q.pop();

    std::cout << q.peek();
    q.pop();

    std::cout << q.isEmpty();
    return 0;
}