#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// saves info from file in a vector
std::vector<double> readNumbers(std::fstream& numbers) {
    std::vector<double> nmb_vec;

    std::string buffer;

    while (!numbers.eof()) {
        numbers >> buffer;
        nmb_vec.push_back(stod(buffer));
    }

    return nmb_vec;
}

std::vector<double> readFunctions(std::fstream& functions) {
    std::vector<double> arg_vec;

    std::string buffer;

    //ignore operator get number
    while (!functions.eof()) {
        functions >> buffer;

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

    // clears eof bit and seeks the beginning of the file
    functions.clear();
    functions.seekg(0, functions.beg);

    // get just the operator
    while (!functions.eof()) {
        functions >> buffer;

        if (buffer[0] == '>' || buffer[0] == '<') {
            buffer.erase(2, buffer.size() - 1);
        }
        else buffer.erase(1, buffer.size() - 1);

        std::copy(buffer.begin(), buffer.end(), std::back_inserter(op_vec));

    }

    return op_vec;
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

bool isInteger(double number) {
    int temp = number;
    if ((number - temp) > 0 || (number - temp) < 0) {
        return 0;
    }
    return 1;
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
    int rows = nmb_vec.size();
    int cols = arg_vec.size();

    double** matrix = makeMatrix(rows, cols);

    for (int row = 0; row < rows;row++) {
        int i = 0;
        for (int col = 0; col < cols; col++) {
            if (op_vec[i] == '<' || op_vec[i] == '>') {
                i++;
            }

            matrix[row][col] = calc(nmb_vec[row], op_vec[i], arg_vec[col]);

            i++;
        }
    }

    printMatrix(matrix, rows, cols);

    deleteMatrix(matrix, rows, cols);
}

// calculates matrix with carry mode
void carryMode(const std::vector<double>& nmb_vec, const std::vector<char>& op_vec, const std::vector<double>& arg_vec) {
    int rows = nmb_vec.size();
    int cols = arg_vec.size();

    double** matrix = makeMatrix(rows, cols);

    for (int row = 0; row < rows;row++) {
        int i = 0;
        for (int col = 0; col < cols; col++) {
            if (col == 0) {
                matrix[row][col] = calc(nmb_vec[row], op_vec[i], arg_vec[col]);
            }
            else matrix[row][col] = calc(nmb_vec[row] + matrix[row][col - 1], op_vec[i], arg_vec[col]);

            if (op_vec[i] == '<' || op_vec[i] == '>') {
                i++;
            }

            i++;
        }
    }

    printMatrix(matrix, rows, cols);

    deleteMatrix(matrix, rows, cols);
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