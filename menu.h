#ifndef MENU_
#define MENU_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "matcal.h"
#include "menufns.h"

void printNumbers(const std::vector<double>& numbers);

void printFunctions(const std::vector<double>& functions, const std::vector<char>& operators);

void main_menu();

void menu(std::vector<double>& nmb_vec, std::vector<char>& op_vec, std::vector<double>& arg_vec);

#endif // MENU_
