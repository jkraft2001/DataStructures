#include <iostream>
#include <stack>
#include <string>

// Check to see if character is operator.
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// If the character is an operator, return the preceding chars (depending on the operator).
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0; // for '('
}

// Converting the expression.
std::string infixToPostfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> operators;

    for (char c : infix) {
        if (c == ' ')
            continue;
        else if (isalnum(c)) // Operand
            postfix += c;
        else if (c == '(')
            operators.push(c);
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Discard '('
        }
        else if (isOperator(c)) { // Operator
            while (!operators.empty() && operators.top() != '(' &&
                precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    // Append remaining operators
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Given.
int main() {
    std::string infixExpression = "((A + B) - C * (D/E)) + F";
    //std::string infixExpression = "A + B * C + D";
    std::string postfixExpression = infixToPostfix(infixExpression);

    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::cout << "Postfix Expression: " << postfixExpression << std::endl;

    return 0;
}
