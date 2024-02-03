// Lab 2 Solution.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Function solution for question 1.
bool isSet(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        auto it = std::find(vec.begin() + i + 1, vec.end(), vec[i]);

        if (it != vec.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> vec1 = { 1, 4, 6, 6, 9 };
    std::vector<int> vec2 = { 1, 4, 5, 6, 1 };

    std::cout << "Vector 1 is a set: " << std::boolalpha << isSet(vec1) << std::endl;
    std::cout << "Vector 2 is a set: " << std::boolalpha << isSet(vec2) << std::endl;

    return 0;
}
