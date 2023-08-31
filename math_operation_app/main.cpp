#include <iostream> 
#include <string>
#include "math_operation.h"
#include "../ipc_library/sender.h"


int main() 
{
    MathOperation mathOp;
    Sender sender("sending_math_operation_queue");

    while (true) 
   {
        double num1, num2;
        char op;
        std::cout << "Enter a mathematical operation in the format: num1 op num2 (e.g., 2 + 2): ";
        std::cin >> num1 >> op >> num2;

        double result;
        std::string error;
        if (mathOp.perform(num1, num2, op, result, error)) 
        {
            std::string message = std::to_string(num1) + " " + op + " " + std::to_string(num2) + " = " + std::to_string(result);
            sender.send(message);
        } 
        else 
        {
            sender.send(error);
        }
    }

    return 0;
}
