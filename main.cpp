﻿#include <iostream>
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

bool isInteger(double numb) {
    int temp = numb;
    if ((numb - temp) > 0) {
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

void deleteMatrix(double** matrix, int rows, int cols) {
    for (int row = 0; row < rows; row++) {
        delete[] matrix[row];
    }
    delete[] matrix;
}

void calculateMatrix(const std::vector<double>& nmb_vec, const std::vector<char>& op_vec, const std::vector<double>& arg_vec, int& m, int& n) {
    int rows = m;
    int cols = n;

    // dynamic matrix
    double** matrix = new double* [rows];

    for (int row = 0; row < rows; row++) {
        matrix[row] = new double[cols];
    }

    for (int row = 0; row < rows;row++) {
        int i = 0;

        for (int col = 0; col < cols; col++) {
            if (op_vec.at(i) == '+') {
                matrix[row][col] = nmb_vec[row] + arg_vec[col];
            }
            else if (op_vec[i] == '-') {
                matrix[row][col] = nmb_vec[row] - arg_vec[col];
            }
            else if (op_vec[i] == '*') {
                matrix[row][col] = nmb_vec[row] * arg_vec[col];
            }
            else if (op_vec[i] == '/') {
                matrix[row][col] = (arg_vec[col] == 0) ? 0 : nmb_vec[row] / arg_vec[col];
            }
            else if (op_vec[i] == '%') {
                if (arg_vec[col] > 0 && nmb_vec[row] > 0 && isInteger(arg_vec[col]) && isInteger(nmb_vec[row])) {
                    matrix[row][col] = (int)nmb_vec[row] % (int)arg_vec[col];
                }
                else matrix[row][col] = 0;
            }
            else if (op_vec[i++] == '<' && arg_vec[col] > 0) {
                if (arg_vec[col] >= 0 && isInteger(arg_vec[col]) && isInteger(nmb_vec[row])) {
                    int nmb = nmb_vec[row], arg = arg_vec[col];
                    matrix[row][col] = nmb << arg;
                }
                else matrix[row][col] = 0;
            }
            else if (op_vec[i++] == '>' && arg_vec[col] != 0) {
                if (arg_vec[col] >= 0 && isInteger(arg_vec[col]) && isInteger(nmb_vec[row])) {
                    int nmb = nmb_vec[row], arg = arg_vec[col];
                    matrix[row][col] = nmb >> arg;
                }
                else matrix[row][col] = 0;
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