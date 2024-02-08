#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform set union
std::vector<int> setUnion(const std::vector<int>& set1, const std::vector<int>& set2) {
    // Store result for returning
    std::vector<int> result;

    // Insert elements from both vectors into result.
    result.insert(result.end(), set1.begin(), set1.end());
    result.insert(result.end(), set2.begin(), set2.end());

    // Sort the vector
    std::sort(result.begin(), result.end());

    // Erase the duplicate values
    result.erase(std::unique(result.begin(), result.end()), result.end());

    return result;
}

// Function to perform set intersection
std::vector<int> setIntersection(const std::vector<int>& set1, const std::vector<int>& set2) {
    // Store result for returning
    std::vector<int> result;

    // Compare set2 to set1 and delete numbers that aren't in both sets.
    for (int num : set1) {
        if (std::find(set2.begin(), set2.end(), num) != set2.end()) {
            result.push_back(num);
        }
    }

    return result;
}

// Function to perform set difference
std::vector<int> setDifference(const std::vector<int>& set1, const std::vector<int>& set2) {
    // Store result for returning
    std::vector<int> result;

    // Compare set2 to set1 and delete index numbers from set1 that aren't in set2
    for (int num : set1) {
        if (std::find(set2.begin(), set2.end(), num) == set2.end()) {
            result.push_back(num);
        }
    }

    return result;
}

int main() {
    std::vector<int> set1 = { 2, 4, 5, 6 };
    std::vector<int> set2 = { 1, 2, 3, 4 };

    std::vector<int> unionSet = setUnion(set1, set2);
    std::vector<int> intersectionSet = setIntersection(set1, set2);
    std::vector<int> differenceSet = setDifference(set1, set2);
    std::vector<int> differenceSet2 = setDifference(set2, set1);

    std::cout << "Set Union: ";
    for (int num : unionSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Set Intersection: ";
    for (int num : intersectionSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Set Difference (Set2 - Set1): ";
    for (int num : differenceSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Set Difference (Set1 - Set2): ";
    for (int num : differenceSet2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
