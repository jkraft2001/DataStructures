// CS400StackApplications(reversing string using a stack).cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <stack>
#include <string>

std::string reverseString(const std::string& input) {
    // Create an empty stack of characters
    std::stack<char> charStack;

    // Push each character onto the stack
    for (char ch : input) {
        charStack.push(ch);
    }

    // Pop characters from the stack to obtain reversed string
    std::string reversedString;
    while (!charStack.empty()) {
        reversedString += charStack.top();
        charStack.pop();
    }

    return reversedString;
}


std::string reverseString_recursion(const std::string& input) {
    if (input.empty()) {
        return "";
    }
    return reverseString(input.substr(1)) + input[0];
}


int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::string reversed = reverseString (input);
    std::cout << "Reversed string: " << reversed << std::endl;

    return 0;
}

