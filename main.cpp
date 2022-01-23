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
* Main file
*
*/
#include <iostream>
#include <fstream>
#include <vector>
#include "ifile.h"
#include "menu.h"

int main() {
    std::fstream myFile1, myFile2;

    myFile1.open("numbers.txt", std::fstream::in);
    myFile2.open("functions.txt", std::fstream::in);

    if (!myFile1.is_open() || !myFile2.is_open()) {
        std::cout << "Error opening file";
        return 1;
    }

    std::vector<double> nmb_vec = readNumbers(myFile1);
    std::vector<double> arg_vec = readFunctions(myFile2);
    std::vector<char> op_vec = readOperators(myFile2);

    myFile1.close();
    myFile2.close();

    menu(nmb_vec, op_vec, arg_vec);

    return 0;
}