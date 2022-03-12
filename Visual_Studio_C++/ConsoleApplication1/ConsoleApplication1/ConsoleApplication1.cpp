
#include <iostream>
#include <iterator>
#include <vector>
#include <array>
#include <array>
#include <algorithm>
#include <list>
#include <memory>

void print(int id, const std::vector<int>& container)
{
    std::cout << id << ". ";
    for (const int x : container) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main()
{

    //=======================================================================
    std::vector<int> c1(1, 999);
    std::vector<int>::iterator it;
    std::vector<int>::reverse_iterator rit;
    print(1, c1);

    it = c1.begin();
    it = c1.insert(it, 200);
    rit = c1.rbegin();

    print(2, c1);
    std::cout << "it is pointing at ....." << * it << std::endl;
    std::cout << "it has the address of ." << & it << std::endl;
    std::cout << "C1.size() === " << c1.size() << std::endl;
    std::cout << "rit is pointing at ....." << *rit << std::endl;
    std::cout << "rit has the address of ." << &rit << std::endl;

    c1.insert(it, 2, 300);
    print(3, c1);

    // `it` no longer valid, get a new one:
    it = c1.begin();

    std::vector<int> c2(2, 400);
    c1.insert(std::next(it, 2), c2.begin(), c2.end());
    print(4, c1);

    int arr[] = { 501,502,503 };
    c1.insert(c1.begin(), arr, arr + std::size(arr));
    print(5, c1);

    c1.insert(c1.end(), { 601,602,603 });
    print(6, c1);

    std::vector<int> int_vector = { 3, 200 };
    print(7, int_vector);

    //==========================================================

    // Create a list containing integers
    std::list<int> l = { 7, 5, 16, 8 };

    // Add an integer to the front of the list
    l.push_front(25);
    // Add an integer to the back of the list
    l.push_back(13);

    // Insert an integer before 16 by searching
    auto lit = std::find(l.begin(), l.end(), 16);
    if (lit != l.end()) {
        l.insert(lit, 42);
    }

    // Print out the list
    std::cout << "list = { ";
    for (int n : l) {
        std::cout << n << ", ";
    }
    std::cout << "};\n";


    //=====================================================================

    std::array<double, 5> a1 = { 19.5, 13.6, 3.50, 45.70, 0.05 };
    std::array<int, 3> a2 = { 1, 2, 3 };  // double braces never required after =

    std::array<std::string, 2> a3 = { std::string("a"), "b" };

    // container operations are supported
    std::sort(a1.begin(), a1.end());
    std::reverse_copy(a2.begin(), a2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // ranged for loop is supported
    for (const auto& s : a1)
        std::cout << s << ' ';
    std::cout << "\n";
    for (const auto& s : a3)
        std::cout << s << ' ';
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
