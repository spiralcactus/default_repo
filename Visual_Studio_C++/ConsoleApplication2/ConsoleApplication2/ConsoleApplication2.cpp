#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>

template <typename M, typename N>
auto multiply(M const& m, N const& n) -> decltype(m + n) { return m + n; };


template <class T>
class Number {
    private:
        T num;
    public:
        Number(T n) : num(n) {} // constructor
        ~Number() {}  // destructor

        T getNum() {
            return num;
        }
};

int main(void)
{
    int is_ok = EXIT_FAILURE;

    static FILE* fp;
    fopen_s(&fp, "test.txt", "w+");

    if (!fp) {
        perror("File opening failed");
        return is_ok;
    }
    fputs("Hello, world!  Today is a very cold day in Dallas.\n", fp);
    fputs("Hello, world!  Today is a very cold day in Dallas.\n", fp);
    fputs("Hello, world!  Today is a very cold day in Dallas.\n", fp);
    fputs("Hello, world!  Today is a very cold day in Dallas.\n", fp);
    rewind(fp);

   std::ofstream myfile;

   myfile.open("example.txt");

    int c; // note: int, not char, required to handle EOF
    while ((c = fgetc(fp)) != EOF) { // standard C I/O file reading loop
        putchar(c);
    }

    if (ferror(fp)) {
        puts("I/O error when reading");
    }
    else if (feof(fp)) {
        puts("End of file reached successfully");
        is_ok = EXIT_SUCCESS;
    }
 
    int a = 3;
    int b = 5;

    std::cout << multiply(6, 75) << std::endl;
    std::cout << multiply(a, b)  << std::endl;
    std::string x = "Hello...";
    std::string y = "..........World.  This is Thomas \n";
    std::cout << multiply(x, y) << std::endl;

    // Create object with in type
    Number<int> numberInt(58);
    // Create object with double type
    Number<double> numberDouble(77.77);

    //fputs is part of C std lib and only output strings
    fputs("int number = %s \n ..........", fp);
    //fstream handles file i/o.
    myfile << "TESTING>>>>=======     " << numberInt.getNum() << std::endl;

    std::cout << "int number = " << numberInt.getNum() << std::endl;
    std::cout << "double number = " << numberDouble.getNum() << std::endl;

    std::array<int, 2> myarray { 3, 5 };
    std::vector<int> myvector(7, 50);
    std::vector<double> Dvector{ 1.0, 2.0, 3.0, 4.0, 5.0 };

    int secondarray[3] = { 1, 2, 3 };

    std::cout << "myarray size is " << myarray.size() << std::endl;
 //   std::cout << secondarray.size() << std::endl;

    std::cout << "myvector size is " << myvector.size() << std::endl;
    std::cout << "Dvector size is " << Dvector.size() << std::endl;

    for (int item : myvector)
        std::cout << "Items in myvector are " << item << std::endl;

    for (double item : Dvector)
        std::cout << "Items in myvector are " << item << std::endl;

    fclose(fp);

    return is_ok;
}