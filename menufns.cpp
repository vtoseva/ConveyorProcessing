#include "menufns.h"

void saveInNewFile(double** mat, int n, int m, bool carry) {
    std::fstream newFile;

    if (!carry) {
        newFile.open("matrix.txt", std::fstream::out);
    }
    else newFile.open("matrix_carry.txt", std::fstream::out);

    if (!newFile.is_open()) {
        return;
    }

    for (int row = 0; row < n;row++) {
        for (int col = 0; col < m; col++) {
            newFile << mat[row][col] << " ";
        }
        newFile << '\n';
    }

    newFile.close();

    std::cout << "\n=======================================================\n\n";
    std::cout << "                   The matrix was saved.\n\n";
    std::cout << "=======================================================\n";

    std::cin.get();
}

void getSaveInNewFile(double** mat, int n, int m, bool carry) {
    std::string input;

    do {
        std::cout << "\n     Do you want to save this matrix in a new file?\n\n";
        std::cout << "                 1. Yes         2. No" << "\n";
        std::cout << "\n=======================================================\n\n                          ";
        std::cin >> input;
        std::cout << "\x1B[2J\x1B[H";
    } while (input != "yes" && input != "Yes" && input != "no" && input != "No" && input != "1" && input != "0" && input != "2");

    if (input == "0" || input == "no" || input == "No" || input == "2") {
        return;
    }
    else saveInNewFile(mat, n, m, carry);
}

// if option to save in file is chosen from the menu the matrix saved is without carry mode
void saveFromMenu(const std::vector<double>& nmb_vec, const std::vector<char>& op_vec, const std::vector<double>& arg_vec) {
    int n = nmb_vec.size();
    int m = arg_vec.size();

    double** matrix = makeMatrix(n, m);
    matrix = calculateMatrix(nmb_vec, op_vec, arg_vec);

    saveInNewFile(matrix, n, m, 0);

    deleteMatrix(matrix, n, m);
}

// changes one number at a time
void changeNumber(std::vector<double>& numbers) {
    int n = numbers.size();
    int pos;

    do {
        printNumbers(numbers);
        std::cout << "=======================================================\n\n";
        std::cout << "  The number on which position do you want to change?\n";
        std::cout << "\n=======================================================\n\n                          ";
        std::cin >> pos;
        std::cout << "\x1B[2J\x1B[H";
    } while (pos < 1 || pos > n);

    std::string new_number;

    do {
        std::cout << "=======================================================\n\n";
        std::cout << "               Please write the new number:\n";
        std::cout << "\n=======================================================\n\n                            ";
        std::cin >> new_number;
        std::cout << "\x1B[2J\x1B[H";
    } while (!isNumber(new_number[0]));

    numbers[pos - 1] = stod(new_number);

    std::cout << "\n=======================================================\n\n";
    std::cout << "                   The new numbers are:\n\n";

    printNumbers(numbers);

    std::cin.get();
}

// changes one function at a time
void changeFunction(std::vector<double>& arguments, std::vector<char>& operators) {
    int m = arguments.size();
    int pos;

    do {
        printFunctions(arguments, operators);
        std::cout << "=======================================================\n\n";
        std::cout << "  The function on which position do you want to change?\n";
        std::cout << "\n=======================================================\n\n                          ";
        std::cin >> pos;
        std::cout << "\x1B[2J\x1B[H";
    } while (pos < 1 || pos > m);

    std::string new_function;

    do {
        std::cout << "=======================================================\n\n";
        std::cout << "             Please write the new function:\n";
        std::cout << "\n=======================================================\n\n                            ";
        std::cin >> new_function;
        std::cout << "\x1B[2J\x1B[H";
    } while (!isFunction(new_function));

    operators[pos - 1] = (new_function[0]);

    if (new_function[0] == '>' || new_function[0] == '<') {
        new_function.erase(0, 2);
    }
    else new_function.erase(0, 1);

    arguments[pos - 1] = stod(new_function);

    std::cout << "\n=======================================================\n\n";
    std::cout << "                 The new functions are:\n\n";

    printFunctions(arguments, operators);

    std::cin.get();
}

void getChangeNumber(std::vector<double>& numbers) {
    std::string input;

    do {
        std::cout << "\n            Do you want to change a number?\n\n";
        std::cout << "                 1. Yes         2. No" << "\n";
        std::cout << "\n=======================================================\n\n                            ";
        std::cin >> input;
        std::cout << "\x1B[2J\x1B[H";
    } while (input != "yes" && input != "Yes" && input != "no" && input != "No" && input != "1" && input != "0" && input != "2");

    if (input == "0" || input == "no" || input == "No" || input == "2") {
        return;
    }
    else changeNumber(numbers);
}

void getChangeFunction(std::vector<double>& arguments, std::vector<char>& operators) {
    std::string input;

    do {
        std::cout << "\n           Do you want to change a function?\n\n";
        std::cout << "                 1. Yes         2. No" << "\n";
        std::cout << "\n=======================================================\n\n                            ";
        std::cin >> input;
        std::cout << "\x1B[2J\x1B[H";
    } while (input != "yes" && input != "Yes" && input != "no" && input != "No" && input != "1" && input != "0" && input != "2");

    if (input == "0" || input == "no" || input == "No" || input == "2") {
        return;
    }
    else changeFunction(arguments, operators);
}