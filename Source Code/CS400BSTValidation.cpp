// CS400BSTValidation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::vector<int> elements;
        inorderTraversal(root, elements);

        for (int i = 1; i < elements.size(); i++) {
            if (elements[i] <= elements[i - 1]) {
                return false;
            }
        }

        return true;
    }

private:
    void inorderTraversal(TreeNode* root, std::vector<int>& elements) {
        if (root == nullptr) {
            return;
        }

        inorderTraversal(root->left, elements);
        elements.push_back(root->val);
        inorderTraversal(root->right, elements);
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution solution;
    if (solution.isValidBST(root)) {
        std::cout << "The binary tree is a valid binary search tree." << std::endl;
    }
    else {
        std::cout << "The binary tree is NOT a valid binary search tree." << std::endl;
    }

    // Don't forget to free the allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

