#include "matcal.h"

void printMatrix(double** matrix, int rows, int cols) {
    std::cout << "=======================================================\n\n";

    for (int row = 0; row < rows;row++) {
        std::cout << "                    ";

        for (int col = 0; col < cols; col++) {
            std::cout << matrix[row][col] << " ";
        }

        std::cout << '\n';
    }

    std::cout << "\n=======================================================\n";
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

double** calculateMatrix(const std::vector<double>& nmb_vec, const std::vector<char>& op_vec, const std::vector<double>& arg_vec) {
    int n = nmb_vec.size();
    int m = arg_vec.size();

    double** matrix = makeMatrix(n, m);

    for (int row = 0; row < n;row++) {
        for (int col = 0; col < m; col++) {
            matrix[row][col] = calc(nmb_vec[row], op_vec[col], arg_vec[col]);
        }
    }

    return matrix;
}

void calculateMatFromMenu(const std::vector<double>& nmb_vec, const std::vector<char>& op_vec, const std::vector<double>& arg_vec) {
    int n = nmb_vec.size();
    int m = arg_vec.size();

    double** matrix = makeMatrix(n, m);

    matrix = calculateMatrix(nmb_vec, op_vec, arg_vec);

    printMatrix(matrix, n, m);

    getSaveInNewFile(matrix, n, m, 0);

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

    getSaveInNewFile(matrix, n, m, 1);

    deleteMatrix(matrix, n, m);
}