// cs400_hw2_wsuID.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <numeric>

// TODO: implement this function to return a Pascal Triangle
std::vector<std::vector<int>> pascalTriangle(int row) {

    if (numRows < 1 || numRows > 16) {
        return {}; // Return empty vector for invalid input
    }

    std::vector<std::vector<int>> triangle(numRows);

    for (int i = 0; i < numRows; ++i) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1; // First and last element of each row is 1

        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}

// TODO: implement this function to print Pascal Triangles 
void printPascalTriangle(const std::vector<std::vector<int>>& triangle) {

}

// TODO: implement this function to return comparison result. See main() for usage. 
std::vector<bool> compare(const std::vector<std::vector<int>>& triangle,
                          const std::vector<int> allegedSummations ) {

    std::vector<bool> comparisonResults;
    for (size_t i = 0; i < triangle.size(); ++i) {
        int actualSum = std::accumulate(triangle[i].begin(), triangle[i].end(), 0);
        comparisonResults.push_back(actualSum == allegedSummations[i]);
    }
    return comparisonResults;

}
     



int main()
{
    // part 1: generate and print Pascal Triangle
    int rows = 8;
    auto triangle = pascalTriangle(rows);
    printPascalTriangle(triangle);
    std::cout << std::endl;

    // part 2: check alleged summations
    // expected returrn: {1, 1, 0, 1, 0, 1, 0, 1, 1, 0}
    std::vector<int> allegedSum{1, 2, 5, 8, 17, 32, 65, 128, 256, 511};
    auto sumCheck = compare(pascalTriangle(allegedSum.size()), allegedSum);
    for (auto b : sumCheck) {
        std::cout << b << " ";
    }

    std::cout << std::endl;

}

