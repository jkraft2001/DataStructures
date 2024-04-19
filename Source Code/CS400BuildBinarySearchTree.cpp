// CS400BuildBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node {
public:
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

int main() {
    BinarySearchTree bst;

    // Insert nodes into the binary search tree
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);
    bst.insert(1);

    // Perform inorder traversal of the binary search tree
    std::cout << "Inorder Traversal: ";
    bst.inorderTraversal(bst.getRoot());
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    bst.preorder();
    std::cout << std::endl;


    std::cout << "Postorder Traversal: ";
    bst.postorder();
    std::cout << std::endl;



    Node* minNode = bst.findMinNode(bst.getRoot());
    std::cout << "min node: " << minNode->data << std::endl;


    Node* maxNode = bst.findMaxNode(bst.getRoot());
    std::cout << "max node: " << maxNode->data << std::endl; 

    // Erase a node from the binary search tree
    bst.erase(3);

    // Perform inorder traversal of the updated binary search tree
    std::cout << "Inorder Traversal: ";
    bst.inorderTraversal(bst.getRoot());
    std::cout << std::endl;


    int searchValue = 5;
    bool found = bst.search(searchValue);
    if (found) {
        std::cout << "Value " << searchValue << " found in the tree." << std::endl;
    }
    else {
        std::cout << "Value " << searchValue << " not found in the tree." << std::endl;
    }

    bst.erase(5);
    // Perform inorder traversal of the binary search tree
    std::cout << "Inorder Traversal: ";
    bst.inorderTraversal(bst.getRoot());
    std::cout << std::endl;





    return 0;
}
