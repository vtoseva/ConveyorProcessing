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
