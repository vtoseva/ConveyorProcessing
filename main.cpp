#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::fstream myFile1, myFile2;

    myFile1.open("numbers.txt", std::fstream::in);
    myFile2.open("functions.txt", std::fstream::in);

    if (!myFile1.is_open() || !myFile2.is_open()) {
        return 1;
    }

    // count
    int m = 0, n = 0;

    std::string buffer, numbers, functions;

    while (getline(myFile1, buffer)) {
        numbers += buffer;
        numbers += " ";
        n++;
    }

    while (getline(myFile2, buffer)) {
        functions += buffer;
        functions += " ";
        m++;
    }

    myFile1.close();
    myFile2.close();

    return 0;
}