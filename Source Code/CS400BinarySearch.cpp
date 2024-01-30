#include <iostream>
#include <vector>



int binarySearch_arr(int arr[], int size, int target) {
    int low = 0; 
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if(arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}




int binarySearch_vec(const std::vector<int>& vi, int target) {
    int low = 0;
    int high = vi.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vi[mid] == target) {
            return mid;  // Found the target element at index mid
        }
        else if (vi[mid] < target) {
            low = mid + 1;  // Search in the upper half
        }
        else {
            high = mid - 1;  // Search in the lower half
        }
    }

    return -1;  // Target element not found
}


int binarySearchRecursive(const std::vector<int>& vi, int target, int low, int high) {
    if (low > high) {
        return -1;  // Target element not found
    }

    int mid = low + (high - low) / 2;

    if (vi[mid] == target) {
        return mid;  // Found the target element at index mid
    }
    else if (vi[mid] < target) {
        return binarySearchRecursive(vi, target, mid + 1, high);  // Search in the upper half
    }
    else {
        return binarySearchRecursive(vi, target, low, mid - 1);  // Search in the lower half
    }
}

int binarySearch(const std::vector<int>& vi, int target) {
    int low = 0;
    int high = vi.size() - 1;

    return binarySearchRecursive(vi, target, low, high);
}

// In the repetitive version, we have only one function call; 
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// In the recursive version, we have n − 1 function calls.
int factorial_recursion(int n) {
    if (n == 0) { // base case
        return 1;
    }
    else {
        return n * factorial_recursion(n - 1);
    }
}






int main() {

    int arr[]{ 10, 20, 30, 40, 50 };
    std::vector<int> vi(arr, arr + std::size(arr));
    int target = 100;
    int result = binarySearch(vi, target);

    std::cout << result << std::endl;;











    //int n = 3;
    //int result = factorial(3);
    //std::cout << result << std::endl;


    //int arr[] = { 1, 2, 3, 4, 5, 6 };
    //
    //int target = 4;

    //int index = binarySearch_arr(arr, std::size(arr), target);

    //if (index != -1) {
    //    std::cout << "Element " << target << " found at index " << index << std::endl;
    //}
    //else {
    //    std::cout << "Element " << target << " not found" << std::endl;
    //}



    /*std::vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int target = 4;

    int index = binarySearch(arr, target);

    if (index != -1) {
        std::cout << "Element " << target << " found at index " << index << std::endl;
    }
    else {
        std::cout << "Element " << target << " not found" << std::endl;
    }*/









    return 0;
}

