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
* Data extraction declaration
*
*/
#ifndef INPUT_FILE
#define INPUT_FILE

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<double> readNumbers(std::fstream& numbers);

std::vector<double> readFunctions(std::fstream& functions);

std::vector<char> readOperators(std::fstream& functions);

#endif // INPUT_FILE
