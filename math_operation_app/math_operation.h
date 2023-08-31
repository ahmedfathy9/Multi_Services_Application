#ifndef MATH_OPERATION_H
#define MATH_OPERATION_H

#include <string>

class MathOperation {
public:
    bool perform(double num1, double num2, char op, double& result, std::string& error);
};

#endif // MATH_OPERATION_H
