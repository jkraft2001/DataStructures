// CS400StackExpressionPostfixEvaluation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>
#include <cmath> // for the pow() function

int evaluatePostfix(const std::string& postfix) {
    std::stack<int> stack;

    // It iterates over each character in the expression
    for (char ch : postfix) {
        if (isdigit(ch)) { // If the character is a digit, 
                           
            //stack.push(static_cast<int>(ch)); // Convert char to integer and push to stack
            stack.push(ch - '0');
        }
        else { // If the character is an operator (+, -, *, /, ^), 
            // it pops two operands from the stack
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            // performs the corresponding operation
            int result;
            switch (ch) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '^':
                result = pow(operand1, operand2);
                break;
            default:
                throw std::runtime_error("Invalid operator encountered");
            }

            // and pushes the result back to the stack.
            stack.push(result);
        }
    }

    return stack.top();
}

int main() {
    std::string postfix = "523*+4-";
    int result = evaluatePostfix(postfix);
    std::cout << "Postfix expression: " << postfix << std::endl;
    std::cout << "Evaluation result: " << result << std::endl;

    return 0;
}
