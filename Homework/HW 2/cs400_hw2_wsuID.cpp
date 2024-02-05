// cs400_hw2_wsuID.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <numeric>

// TODO: implement this function to return a Pascal Triangle
std::vector<std::vector<int>> pascalTriangle(int row) {

    return {};
}

// TODO: implement this function to print Pascal Triangles 
void printPascalTriangle(const std::vector<std::vector<int>>& triangle) {

}

// TODO: implement this function to return comparison result. See main() for usage. 
std::vector<bool> compare(const std::vector<std::vector<int>>& triangle,
                          const std::vector<int> allegedSummations ) {

    return {};

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

