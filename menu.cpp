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
* Menu implementation
*
*/
#include "menu.h"

void printNumbers(const std::vector<double>& numbers) {
    std::cout << "=======================================================\n\n";
    std::cout << "                    ";

    for (double number : numbers) {
        std::cout << number << " ";
    }

    std::cout << "\n\n=======================================================\n";
}

void printFunctions(const std::vector<double>& functions, const std::vector<char>& operators) {
    std::cout << "=======================================================\n\n";
    std::cout << "                  ";

    int m = functions.size();

    for (int i = 0; i < m; i++) {
        if (operators[i] == '<') {
            std::cout << '<';
        }
        if (operators[i] == '>') {
            std::cout << '>';
        }
        std::cout << operators[i] << functions[i] << " ";
    }

    std::cout << "\n\n=======================================================\n";
}

void main_menu() {
    std::cout << "=======================================================" << "\n";

    std::cout << "                  1. See numbers\n";
    std::cout << "                  2. Change numbers\n";
    std::cout << "                  3. See functions\n";
    std::cout << "                  4. Change functions\n";
    std::cout << "                  5. Calculate matrix\n";
    std::cout << "                  6. Carry mode\n";
    std::cout << "                  7. Save in a file\n";
    std::cout << "                  8. Exit\n";

    std::cout << "=======================================================" << "\n";

    std::cout << "\n";
}

void menu(std::vector<double>& nmb_vec, std::vector<char>& op_vec, std::vector<double>& arg_vec) {
    std::cout << "\x1B[2J\x1B[H";

    int userInput;

    do {
        main_menu();
        std::cout << "                   Choose option: ";
        std::cin >> userInput;
        std::cout << "\n=======================================================\n";
        std::cout << "\x1B[2J\x1B[H";
    } while (userInput > 8 || userInput < 1);

    // Exit
    if (userInput == 8) {
        return;
    }

    switch (userInput) {
    case 1: printNumbers(nmb_vec);
        getChangeNumber(nmb_vec);
        break;
    case 2: changeNumber(nmb_vec);
        break;
    case 3: printFunctions(arg_vec, op_vec);
        getChangeFunction(arg_vec, op_vec);
        break;
    case 4: changeFunction(arg_vec, op_vec);
        break;
    case 5:
        calculateMatFromMenu(nmb_vec, op_vec, arg_vec);
        break;
    case 6: carryMode(nmb_vec, op_vec, arg_vec);
        break;
    case 7: saveFromMenu(nmb_vec, op_vec, arg_vec);
        break;
    default:
        break;
    }

    std::cin.get();

    menu(nmb_vec, op_vec, arg_vec);
}