// CS400StackApplications(infix to postfix).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>

// TODO: implement infixToPostfix function, build other functions as you need.
std::string infixToPostfix(const std::string& infix) {
    









}



// use main function to test your solution:
int main() {
    std::string infixExpression = "((A + B) - C * (D/E)) + F";
    //std::string infixExpression = "A + B * C + D";
    std::string postfixExpression = infixToPostfix(infixExpression);

    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::cout << "Postfix Expression: " << postfixExpression << std::endl;

    return 0;
}

