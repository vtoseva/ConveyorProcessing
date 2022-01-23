#ifndef MATRIX_CALC
#define MATRIX_CALC

#include <iostream>
#include <string>
#include <vector>
#include "valid.h"
#include "menufns.h"

void printMatrix(double** matrix, int rows, int cols);

double** makeMatrix(int m, int n);

void deleteMatrix(double** matrix, int rows, int cols);

double calc(double nmb, char op, double arg);

double** calculateMatrix(const std::vector<double>& nmb_vec, const std::vector<char>& op_vec, const std::vector<double>& arg_vec);

void calculateMatFromMenu(const std::vector<double>& nmb_vec, const std::vector<char>& op_vec, const std::vector<double>& arg_vec);

// calculates matrix with carry mode
void carryMode(const std::vector<double>& nmb_vec, const std::vector<char>& op_vec, const std::vector<double>& arg_vec);

#endif // MATRIX_CALC