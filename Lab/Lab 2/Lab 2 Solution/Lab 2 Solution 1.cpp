// Lab 2 Solution.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Function solution for question 1.
bool isSet(const std::vector<int>& vec) {
    // Iterate through the vector
    for (size_t i = 0; i < vec.size(); ++i) {
        // Search for the current element in the vector after the current position
        auto it = std::find(vec.begin() + i + 1, vec.end(), vec[i]);

        // If the element is found beyond the current position, it's a duplicate
        if (it != vec.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> vec1 = { 1, 4, 5, 6, 9 };
    std::vector<int> vec2 = { 1, 4, 5, 6, 1 };

    std::cout << "Vector 1 is a set: " << std::boolalpha << isSet(vec1) << std::endl;
    std::cout << "Vector 2 is a set: " << std::boolalpha << isSet(vec2) << std::endl;

    return 0;
}
