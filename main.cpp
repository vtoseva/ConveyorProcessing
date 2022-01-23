#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// saves info from file in a vector
std::vector<double> readNumbers(std::fstream& numbers) {
    std::vector<double> nmb_vec;

    std::string buffer;

    while (getline(numbers, buffer)) {
        nmb_vec.push_back(stod(buffer));
    }

    return nmb_vec;
}

std::vector<double> readFunctions(std::fstream& functions) {
    std::vector<double> arg_vec;

    std::string buffer;

    //ignore operator get number
    while (getline(functions, buffer)) {
        if (buffer[0] == '>' || buffer[0] == '<') {
            buffer.erase(0, 2);
        }
        else buffer.erase(0, 1);

        arg_vec.push_back(stod(buffer));
    }

    return arg_vec;
}

std::vector<char> readOperators(std::fstream& functions) {
    std::vector<char> op_vec;

    std::string buffer;

    // seeks the beginning of the file
    functions.clear();
    functions.seekg(0, functions.beg);

    // get just the operator
    while (getline(functions, buffer)) {
        buffer.erase(1, buffer.size() - 1);

        std::copy(buffer.begin(), buffer.end(), std::back_inserter(op_vec));
    }

    return op_vec;
}

void printNumbers(const std::vector<double>& numbers) {
    std::cout << "=======================================================\n\n";
    std::cout << "                    ";

    for (double number : numbers) {
        std::cout << number << " ";
    }

    std::cout << "\n\n=======================================================\n";
}

void printFunctions(const std::vector<double>& functions, const std::vector<char>& operators) {
    std::cout << "=======================================================\n\n";
    std::cout << "                  ";

    int m = functions.size();

    for (int i = 0; i < m; i++) {
        if (operators[i] == '<') {
            std::cout << '<';
        }
        if (operators[i] == '>') {
            std::cout << '>';
        }
        std::cout << operators[i] << functions[i] << " ";
    }

    std::cout << "\n\n=======================================================\n";
}

bool isInteger(double number) {
    int temp = number;

    if ((number - temp) > 0 || (number - temp) < 0) {
        return 0;
    }

    return 1;
}

bool isFunction(const std::string str) {
    if (str[0] == '<') {
        if (!isNumber(str[2]) || str[1] != '<')
            return 0;
    }
    else return true;

    if (str[0] == '>') {
        if (!isNumber(str[2]) || str[1] != '>')
            return 0;
    }
    else return true;

    return (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/' || str[0] == '%') && isNumber(str[1]);
}

bool isNumber(const char c) {
    return c >= '0' && c <= '9';
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

    if (input == "0" || input == "no" || input == "No" || input != "2") {
        return;
    }
    else saveInNewFile(mat, n, m, carry);
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

void printMatrix(double** matrix, int rows, int cols) {
    for (int row = 0; row < rows;row++) {
        for (int col = 0; col < cols; col++) {
            std::cout << matrix[row][col] << " ";
        }
        std::cout << '\n';
    }
}

double** makeMatrix(int m, int n) {
    double** matrix = new double* [m];

    for (int row = 0; row < m; row++) {
        matrix[row] = new double[n];
    }

    return matrix;
}

void deleteMatrix(double** matrix, int rows, int cols) {
    for (int row = 0; row < rows; row++) {
        delete[] matrix[row];
    }
    delete[] matrix;
}

// does operation
double calc(double nmb, char op, double arg) {
    double result = 0;

    if (op == '+') {
        result = nmb + arg;
    }
    else if (op == '-') {
        result = nmb - arg;
    }
    else if (op == '*') {
        result = nmb * arg;
    }
    else if (op == '/') {
        result = (arg == 0) ? 0 : nmb / arg;
    }
    else if (op == '%') {
        if (arg > 0 && nmb > 0 && isInteger(arg) && isInteger(nmb)) {
            result = (int)nmb % (int)arg;
        }
        else result = 0;
    }
    else if (op == '<') {
        if (arg >= 0 && isInteger(arg) && isInteger(nmb)) {
            result = (int)nmb << (int)arg;
        }
        else result = 0;
    }
    else if (op == '>') {
        if (arg >= 0 && isInteger(arg) && isInteger(arg)) {
            result = (int)nmb >> (int)arg;
        }
        else result = 0;
    }

    return result;
}

void calculateMatrix(const std::vector<double>& nmb_vec, const std::vector<char>& op_vec, const std::vector<double>& arg_vec) {
    //dynamic matrix
    int n = nmb_vec.size();
    int m = arg_vec.size();

    double** matrix = makeMatrix(n, m);

    for (int row = 0; row < n;row++) {
        for (int col = 0; col < m; col++) {
            matrix[row][col] = calc(nmb_vec[row], op_vec[col], arg_vec[col]);
        }
    }

    printMatrix(matrix, n, m);

    saveInNewFile(matrix, n, m, 0);

    deleteMatrix(matrix, n, m);
}

// calculates matrix with carry mode
void carryMode(const std::vector<double>& nmb_vec, const std::vector<char>& op_vec, const std::vector<double>& arg_vec) {
    int n = nmb_vec.size();
    int m = arg_vec.size();

    double** matrix = makeMatrix(n, m);

    for (int row = 0; row < n;row++) {
        for (int col = 0; col < m; col++) {
            if (col == 0) {
                matrix[row][col] = calc(nmb_vec[row], op_vec[col], arg_vec[col]);
            }
            else matrix[row][col] = calc(nmb_vec[row] + matrix[row][col - 1], op_vec[col], arg_vec[col]);
        }
    }

    printMatrix(matrix, n, m);

    saveInNewFile(matrix, n, m, 1);

    deleteMatrix(matrix, n, m);
}

int main()
{
    std::fstream myFile1, myFile2;

    myFile1.open("numbers.txt", std::fstream::in);
    myFile2.open("functions.txt", std::fstream::in);

    if (!myFile1.is_open() || !myFile2.is_open()) {
        return 1;
    }

    std::vector<double> nmb_vec = readNumbers(myFile1);
    std::vector<double> arg_vec = readFunctions(myFile2);
    std::vector<char> op_vec = readOperators(myFile2);

    // count of elements
    int n = nmb_vec.size(), m = arg_vec.size();

    myFile1.close();
    myFile2.close();

    return 0;
}