// CS400QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

// Function to swap two elements in the array
//void swap(int& a, int& b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}

// Function to partition the array and return the index of the pivot element
int partition(std::vector<int>& vi, int low, int high) {
    int pivot = vi[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (vi[j] > pivot) {
            i++;
            std::swap(vi[i], vi[j]);
        }
    }

    std::swap(vi[i + 1], vi[high]);
    return i + 1;
}

// Function to perform the QuickSort algorithm
void quickSort(std::vector<int>& vi, int low, int high) {
    if (low < high) {
        // Partition the array into two sub-arrays
        int pivotIndex = partition(vi, low, high);

        // Recursively sort the sub-arrays
        quickSort(vi, low, pivotIndex - 1);
        quickSort(vi, pivotIndex + 1, high);
    }
}

int main() {
    std::vector<int> vi = { 30, 90, 10, 80, 40, 50, 70 };

    std::cout << "Original array: ";
    for (int num : vi) {
        std::cout << num << " ";
    }

    quickSort(vi, 0, vi.size() - 1);

    std::cout << "\nSorted array: ";
    for (int num : vi) {
        std::cout << num << " ";
    }

    return 0;
}

