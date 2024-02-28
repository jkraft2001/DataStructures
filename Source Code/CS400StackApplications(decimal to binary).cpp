// CS400StackApplications(decimal to binary).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>
#include <vector>



void decimalToBinary_vec(int number) {
    std::vector<int> vi;

    while (number > 0) {
        vi.push_back(number % 2);
        number /= 2;
    }

    for (int i = 0; i < (vi.size() / 2); i++) {
        //int temp = vi.at(i);
        //vi.at(i) = vi.at(vi.size() - 1 - i);
        //vi.at(vi.size() - 1 - i) = temp;
        std::swap(vi.at(i), vi.at(vi.size() - 1 - i));
    }

    for (int i : vi) {
        std::cout << i << std::endl;
    }
}










std::string decimalToBinary_stack(int decimal) {
    std::stack<int> binaryStack;

    while (decimal > 0) {
        //int remainder = decimal % 2;
        binaryStack.push(decimal % 2);
        decimal /= 2;
    }

    std::string binary;

    while (!binaryStack.empty()) {
        binary += std::to_string(binaryStack.top());
        binaryStack.pop();
    }

    return binary;
}




int main() {
    int decimal = 5;
    std::string binary = decimalToBinary_stack(decimal);

    std::cout << "Decimal: " << decimal << std::endl;
    std::cout << "Binary: " << binary << std::endl;

    return 0;
}

