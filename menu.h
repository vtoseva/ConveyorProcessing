/**
*
* Solution to course project # 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Violina Toseva
* @idnumber 7MI0600070
* @compiler VC
*
* Menu declaration
*
*/
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
