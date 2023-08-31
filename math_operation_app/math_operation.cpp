#include "math_operation.h"
#include <string>

bool MathOperation::perform(double num1, double num2, char op, double& result, std::string& error) {
    switch (op) {
    case '+':
        result = num1 + num2;
        return true;
    case '-':
        result = num1 - num2;
        return true;
    case '*':
        result = num1 * num2;
        return true;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
            return true;
        } else {
            error = "Error: Division by zero";
            return false;
        }
    default:
        error = "Error: Unknown operator";
        return false;
    }
}
