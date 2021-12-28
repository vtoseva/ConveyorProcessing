#include <iostream>
#include <fstream>
#include <string>

// saves info from file in a string and counts elements
void read(std::fstream& myFile, std::string& str, int& count) {
    std::string buffer;

    while (getline(myFile, buffer)) {
        str += buffer;
        str += " ";
        count++;
    }
}

void main_menu() {

    std::cout << "1. See numbers\n";
    std::cout << "2. Change numbers\n";
    std::cout << "3. See functions\n";
    std::cout << "4. Change functions\n";
    std::cout << "5. Calculate matrix\n";
    std::cout << "6. Carry mode\n";
    std::cout << "7. Save in a file\n";
    std::cout << "8. Exit\n";

    std::cout << "\n";

    std::cout << "Choose option: \n";

}

void options(int userInput) {
    switch (userInput) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    default:
        break;
    }
}

void menu() {
}

int main()
{
    std::fstream myFile1, myFile2;

    myFile1.open("numbers.txt", std::fstream::in);
    myFile2.open("functions.txt", std::fstream::in);

    if (!myFile1.is_open() || !myFile2.is_open()) {
        return 1;
    }

    // count
    int n = 0, m = 0;

    std::string numbers, functions;

    read(myFile1, numbers, n);
    read(myFile2, functions, m);

    myFile1.close();
    myFile2.close();

    return 0;
}