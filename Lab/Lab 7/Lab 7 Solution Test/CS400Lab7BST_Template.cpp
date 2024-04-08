#include <iostream>

template<typename T>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;

    // Constructor
    Node(const T& val) : value(val), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinarySearchTree {
private:
    Node<T>* root;

    // Helper functions
    Node<T>* makeNode(const T& value) {
        return new Node<T>(value);
    }

    void destroyTree(Node<T>* currentNode) {
        if (currentNode == nullptr) {
            return;
        }
        destroyTree(currentNode->left);
        destroyTree(currentNode->right);
        delete currentNode;
    }

    Node<T>* insertNode(Node<T>* currentNode, const T& value) {
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

    Node<T>* findNode(Node<T>* currentNode, const T& value) const {
        if (currentNode == nullptr || currentNode->value == value) {
            return currentNode;
        }
        if (value < currentNode->value) {
            return findNode(currentNode->left, value);
        }
        return findNode(currentNode->right, value);
    }

    void inorderTraversal(Node<T>* currentNode) const {
        if (currentNode != nullptr) {
            inorderTraversal(currentNode->left);
            std::cout << currentNode->value << " ";
            inorderTraversal(currentNode->right);
        }
    }

    void preorderTraversal(Node<T>* currentNode) const {
        if (currentNode != nullptr) {
            std::cout << currentNode->value << " ";
            preorderTraversal(currentNode->left);
            preorderTraversal(currentNode->right);
        }
    }

    void postorderTraversal(Node<T>* currentNode) const {
        if (currentNode != nullptr) {
            postorderTraversal(currentNode->left);
            postorderTraversal(currentNode->right);
            std::cout << currentNode->value << " ";
        }
    }

    Node<T>* findMinNode(Node<T>* currentNode) {
        if (currentNode == nullptr || currentNode->left == nullptr) {
            return currentNode;
        }
        return findMinNode(currentNode->left);
    }

    Node<T>* findMaxNode(Node<T>* currentNode) {
        if (currentNode == nullptr || currentNode->right == nullptr) {
            return currentNode;
        }
        return findMaxNode(currentNode->right);
    }

    Node<T>* eraseNode(Node<T>* currentNode, const T& value) {
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
                Node<T>* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == nullptr) {
                Node<T>* temp = currentNode->left;
                delete currentNode;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node<T>* temp = findMinNode(currentNode->right);

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

    void insert(const T& value) {
        root = insertNode(root, value);
    }

    bool search(const T& value) const {
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

    Node<T>* findMinNode() {
        return findMinNode(root);
    }

    Node<T>* findMaxNode() {
        return findMaxNode(root);
    }

    void erase(const T& value) {
        root = eraseNode(root, value);
    }

    Node<T>* getRoot() {
        return root;
    }
};

/*
int main() {
    BinarySearchTree<int> bst;

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
*/