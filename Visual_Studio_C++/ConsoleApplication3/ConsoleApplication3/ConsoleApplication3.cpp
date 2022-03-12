// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int len, int bth)
    {
        length = len;
        breadth = bth;
    }

    int area()
    {
        return length * breadth;
    }
};

int main()
{
    std::cout << "Hello World!\n";

    std::unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    std::cout << P1->area() << std::endl;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
