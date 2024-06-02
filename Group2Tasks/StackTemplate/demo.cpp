#include <iostream>

#include "Stack.h"

int main ()
{
    Stack<int> stak;

    for (int i = 0; i < 5; i++)
    {
        int num(0);
        std::cin >> num;

        stak.push(num);
    }

    stak.print(); std::cout << '\n';
    stak.pop();
    stak.print(); std::cout << '\n';

    return 0;
}