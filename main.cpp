#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// saves info from file in a vector
void read(std::fstream& numbers, std::fstream& functions, std::vector<double>& nmb_vec, std::vector<char>& op_vec, std::vector<double>& arg_vec, int& n, int& m) {
    std::string buffer;

    while (getline(numbers, buffer)) {
        nmb_vec.push_back(stod(buffer));
        n++;
    }

    std::string argument;

    while (getline(functions, buffer)) {
        int i = 0;

        while (i < buffer.length()) {
            op_vec.push_back(buffer[i++]);
            if (buffer[i] == '>' || buffer[i] == '<') {
                op_vec.push_back(buffer[i++]);
            }
            argument = buffer[i++];
            m++;
        }

        arg_vec.push_back(stod(argument));
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

    std::vector<double> nmb_vec;
    std::vector<double> arg_vec;
    std::vector<char> op_vec;

    read(myFile1, myFile2, nmb_vec, op_vec, arg_vec, n, m);

    myFile1.close();
    myFile2.close();

    return 0;
}