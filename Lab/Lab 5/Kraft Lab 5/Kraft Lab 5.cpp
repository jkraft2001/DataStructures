#include <iostream>
#include <stack>
#include <string>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0; // for '('
}

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

int main() {
    //std::string infixExpression = "((A + B) - C * (D/E)) + F";
    std::string infixExpression = "A + B * C + D";
    std::string postfixExpression = infixToPostfix(infixExpression);

    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::cout << "Postfix Expression: " << postfixExpression << std::endl;

    return 0;
}
