#ifndef MENU_FUNCTIONS
#define MENU_FUNCTIONS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "matcal.h"
#include "valid.h"
#include "menu.h"

void saveInNewFile(double** mat, int n, int m, bool carry);

void getSaveInNewFile(double** mat, int n, int m, bool carry);

// if option to save in file is chosen from the menu the matrix saved is without carry mode
void saveFromMenu(const std::vector<double>& nmb_vec, const std::vector<char>& op_vec, const std::vector<double>& arg_vec);

// changes one number at a time
void changeNumber(std::vector<double>& numbers);

// changes one function at a time
void changeFunction(std::vector<double>& arguments, std::vector<char>& operators);

void getChangeNumber(std::vector<double>& numbers);

void getChangeFunction(std::vector<double>& arguments, std::vector<char>& operators);

#endif // MENU_FUNCTIONS
