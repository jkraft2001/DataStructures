#include <iostream>
#include <vector>

void insertionSort_vec(std::vector<int>& vi) {
    
    for (int i = 1; i < vi.size(); ++i) {
        int key = vi[i];

        int j = i - 1;
        while (j >= 0 && vi[j] < key) {
            vi[j + 1] = vi[j];
            --j;
        }

        vi[j + 1] = key;
    }
}

void insertionSort_arr(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}














int main() {
    
    std::vector<int> vi = { 5, 2, 4, 6, 1, 3 };

    std::cout << "Before sorting: ";
    for (int num : vi) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    insertionSort_vec(vi);

    std::cout << "After sorting: ";
    for (int num : vi) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

















    //int arr[] = { 5, 2, 4, 6, 1, 3 };
    //int n = sizeof(arr) / sizeof(arr[0]);

    //std::cout << "Before sorting: ";
    //for (int i = 0; i < n; ++i) {
    //    std::cout << arr[i] << " ";
    //}
    //std::cout << std::endl;

    //insertionSort(arr, n);

    //std::cout << "After sorting: ";
    //for (int i = 0; i < n; ++i) {
    //    std::cout << arr[i] << " ";
    //}
    //std::cout << std::endl;













    return 0;
}

