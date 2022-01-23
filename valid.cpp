#include "valid.h"

bool isInteger(double number) {
    int temp = number;

    if ((number - temp) > 0 || (number - temp) < 0) {
        return 0;
    }

    return 1;
}

bool isNumber(const char c) {
    return c >= '0' && c <= '9';
}

bool isFunction(const std::string str) {
    if (str[0] == '<') {
        if (!isNumber(str[2]) || str[1] != '<')
            return 0;
    }
    else if (str[0] == '>') {
        if (!isNumber(str[2]) || str[1] != '>')
            return 0;
    }
    else if (!((str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/' || str[0] == '%') && isNumber(str[1])))
        return 0;

    return 1;
}