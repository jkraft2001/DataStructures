// Quiz4Prep_CS400.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;


struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		data = value;
		left = nullptr;
		right = nullptr;
	}
};

class BinarySearchTree {
private:
    Node* root;
    int count;

    void destroyTree(Node* currentNode) {
        if (currentNode == nullptr) {
            return;
        }

        destroyTree(currentNode->left);
        destroyTree(currentNode->right);
        delete currentNode;
    }

    void preorderTraversal(Node* currentNode) const {
        if (currentNode == nullptr) {
            return;
        }

        std::cout << currentNode->data << " ";
        preorderTraversal(currentNode->left);
        preorderTraversal(currentNode->right);
    }

    void postorderTraversal(Node* currentNode) const {
        if (currentNode == nullptr) {
            return;
        }

        postorderTraversal(currentNode->left);
        postorderTraversal(currentNode->right);
        std::cout << currentNode->data << " ";
    }

    bool searchNode(Node* currentNode, int value) const {
        if (currentNode == nullptr) {
            return false;
        }

        if (currentNode->data == value) {
            return true;
        }

        if (value < currentNode->data) {
            return searchNode(currentNode->left, value);
        }
        else {
            return searchNode(currentNode->right, value);
        }
    }

    //Node* insertNode(Node* currentNode, int value) {
    //    if (currentNode == nullptr) {
    //        return new Node(value);
    //    }

    //    if (value < currentNode->data) {
    //        currentNode->left = insertNode(currentNode->left, value);
    //    }
    //    else {
    //        currentNode->right = insertNode(currentNode->right, value);
    //    }

    //    
    // 
    //}


    void insertNode(Node*& currentNode, int value) {
        if (!currentNode) {
            currentNode = new Node(value);
            return;
        }

        if (value < currentNode->data) {
            insertNode(currentNode->left, value);
        }
        else {
            insertNode(currentNode->right, value);
        }

    }




    Node* eraseNode(Node* currentNode, int value) {
        if (currentNode == nullptr) {
            return nullptr;  // The value is not found.
        }

        // Search for the node to be deleted.
        if (value < currentNode->data) {
            currentNode->left = eraseNode(currentNode->left, value);
        }
        else if (value > currentNode->data) {
            currentNode->right = eraseNode(currentNode->right, value);
        }
        else {
            // Found the node to be deleted.

            // Case 1: Node has no children or only one child.
            if (currentNode->left == nullptr) {
                Node* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == nullptr) {
                Node* temp = currentNode->left;
                delete currentNode;
                return temp;
            }

            // Case 2: Node has two children.

            // // find the minimum value in its right subtree (inorder successor)
            //Node* successor = findMinNode(currentNode->right);
            // // Replace the node's value with the value of the successor found in the subtree.
            //currentNode->data = successor->data;
            // // Recursively delete the successor node from the subtree.
            //currentNode->right = eraseNode(currentNode->right, successor->data);

            // find the maximum value in its left subtree (inorder predecessor)
            Node* predecessor = findMaxNode(currentNode->left);
            // Replace the node's value with the value of the predecessor found in the subtree.
            currentNode->data = predecessor->data;
            // Recursively delete the predecessor node from the subtree.
            currentNode->left = eraseNode(currentNode->left, predecessor->data);

        }

        return currentNode;
    }


public:
    BinarySearchTree() {
        root = nullptr;
        count = 0;
    }

    ~BinarySearchTree() {
        destroyTree(root);
    }

    /*void insert(int value) {
        root = insertNode(root, value);
        count++;
    }*/

    void insert(int value) {
        insertNode(root, value);
        count++;
    }

    bool search(int value) const {
        return searchNode(root, value);
    }

    void inorderTraversal(Node* currentNode) {
        if (currentNode != nullptr) {
            inorderTraversal(currentNode->left);
            std::cout << currentNode->data << " ";
            inorderTraversal(currentNode->right);
        }
    }

    void preorder() const {
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void postorder() const {
        postorderTraversal(root);
        std::cout << std::endl;
    }

    Node* getRoot() {
        return root;
    }



    Node* findMinNode(Node* root) {
        if (root == nullptr) {
            return nullptr;  // The tree or subtree is empty.
        }

        while (root->left != nullptr) {
            root = root->left;  // Traverse to the leftmost node.
        }

        return root;
    }


    Node* findMaxNode(Node* root) {
        if (root == nullptr) {
            return nullptr;  // The tree or subtree is empty.
        }

        while (root->right != nullptr) {
            root = root->right;  // Traverse to the rightmost node.
        }

        return root;
    }

    void erase(int value) {
        root = eraseNode(root, value);
        count--;
    }

};

class bstValidation {
public:
    bool isValid(Node* root) {
        vector<int> elements;
        inorderTraversal(root, elements);

        for (int i = 1; i < elements.size(); i++) {
            if (elements[i] <= elements[i - 1]) {
                return false;
            }
        }

        return true;
    }

private:
    void inorderTraversal(Node* root, std::vector<int>& elements) {
        if (root == nullptr) {
            return;
        }

        inorderTraversal(root->left, elements);
        elements.push_back(root->data);
        inorderTraversal(root->right, elements);
    }
};

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

int binarySearch_arr(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
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