#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    // Helper functions
    Node* makeNode(int value) {
        return new Node(value);
    }

    void destroyTree(Node* currentNode) {
        if (currentNode == nullptr) {
            return;
        }
        destroyTree(currentNode->left);
        destroyTree(currentNode->right);
        delete currentNode;
    }

    Node* insertNode(Node* currentNode, int value) {
        if (currentNode == nullptr) {
            return makeNode(value);
        }
        if (value < currentNode->value) {
            currentNode->left = insertNode(currentNode->left, value);
        }
        else if (value > currentNode->value) {
            currentNode->right = insertNode(currentNode->right, value);
        }
        return currentNode;
    }

    Node* findNode(Node* currentNode, int value) const {
        if (currentNode == nullptr || currentNode->value == value) {
            return currentNode;
        }
        if (value < currentNode->value) {
            return findNode(currentNode->left, value);
        }
        return findNode(currentNode->right, value);
    }

    void inorderTraversal(Node* currentNode) const {
        if (currentNode != nullptr) {
            inorderTraversal(currentNode->left);
            cout << currentNode->value << " ";
            inorderTraversal(currentNode->right);
        }
    }

    void preorderTraversal(Node* currentNode) const {
        if (currentNode != nullptr) {
            cout << currentNode->value << " ";
            preorderTraversal(currentNode->left);
            preorderTraversal(currentNode->right);
        }
    }

    void postorderTraversal(Node* currentNode) const {
        if (currentNode != nullptr) {
            postorderTraversal(currentNode->left);
            postorderTraversal(currentNode->right);
            cout << currentNode->value << " ";
        }
    }

    Node* findMinNode(Node* currentNode) {
        if (currentNode == nullptr || currentNode->left == nullptr) {
            return currentNode;
        }
        return findMinNode(currentNode->left);
    }

    Node* findMaxNode(Node* currentNode) {
        if (currentNode == nullptr || currentNode->right == nullptr) {
            return currentNode;
        }
        return findMaxNode(currentNode->right);
    }

    Node* eraseNode(Node* currentNode, int value) {
        if (currentNode == nullptr) {
            return nullptr;
        }
        if (value < currentNode->value) {
            currentNode->left = eraseNode(currentNode->left, value);
        }
        else if (value > currentNode->value) {
            currentNode->right = eraseNode(currentNode->right, value);
        }
        else {
            // Node to be deleted found

            // Node with only one child or no child
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

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMinNode(currentNode->right);

            // Copy the inorder successor's content to this node
            currentNode->value = temp->value;

            // Delete the inorder successor
            currentNode->right = eraseNode(currentNode->right, temp->value);
        }
        return currentNode;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    bool search(int value) const {
        return findNode(root, value) != nullptr;
    }

    void inorder() const {
        inorderTraversal(root);
    }

    void preorder() const {
        preorderTraversal(root);
    }

    void postorder() const {
        postorderTraversal(root);
    }

    Node* findMinNode() {
        return findMinNode(root);
    }

    Node* findMaxNode() {
        return findMaxNode(root);
    }

    void erase(int value) {
        root = eraseNode(root, value);
    }

    Node* getRoot() {
        return root;
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
    bst.inorder();
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    bst.preorder();
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    bst.postorder();
    std::cout << std::endl;

    // Erase a node from the binary search tree
    bst.erase(3);

    // Perform inorder traversal of the updated binary search tree
    std::cout << "Inorder Traversal: ";
    bst.inorder();
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
    bst.inorder();
    std::cout << std::endl;

    return 0;
}
