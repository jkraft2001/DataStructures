#include <iostream>
#include <string>
#include <stack>

std::string decimalToHexadecimal(int decimal) {
    std::stack<char> hexDigits;
    std::string hexString = "";

    // Convert decimal to hexadecimal
    while (decimal != 0) {
        int remainder = decimal % 16;

        // Convert remainder to hexadecimal digit
        char hexDigit;
        if (remainder < 10) {
            hexDigit = remainder + '0';
        }
        else {
            hexDigit = remainder - 10 + 'A';
        }

        // Push the hexadecimal digit onto the stack
        hexDigits.push(hexDigit);

        // Update decimal for the next iteration
        decimal /= 16;
    }

    // Pop digits from stack to construct the hexadecimal string
    while (!hexDigits.empty()) {
        hexString += hexDigits.top();
        hexDigits.pop();
    }

    return hexString;
}

int main() {
    int decimalNumber;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;

    std::string hexadecimalNumber = decimalToHexadecimal(decimalNumber);
    std::cout << "Hexadecimal representation: " << hexadecimalNumber << std::endl;

    return 0;
}

