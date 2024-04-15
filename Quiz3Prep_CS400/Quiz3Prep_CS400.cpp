// Quiz3Prep_CS400.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x): data(x), left(nullptr), right(nullptr){}
};

struct Job {
    string name;
    int priority;

    Job(const string& n, int p) : name(n), priority(p) {}
};

struct Person {
    string name;
    int age;

    Person(const string& n, int a): name(n), age(a){}
};

struct CompareByAge {
    bool operator()(const Person& p1, const Person& p2) {
        return p1.age < p2.age;
    }
};

class BinarySearchTree {
public:
    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            root = new Node(data);
        }
        else if (data < root->data) {
            root->left = insert(root->left, data);
        }
        else {
            root->right = insert(root->right, data);
        }

        return root;
    }

    // Great for deletion.
    void postOrderTraversal(Node* root) {
        if (root == nullptr) return;

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";

        // Instead of cout, when a destructor is involved, use the below line along with the above helper function.
        // delete data;
    }

    // Great for accessing the root of the tree/subtree first.
    void preOrderTraversal(Node* root) {
        if (root == nullptr) return;

        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void inOrderTraversal(Node* root) {
        if (root == nullptr) return;

        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
};

void scheduleJob(queue<Job>& jobQueue) {
    while (!jobQueue.empty()) {
        Job job = jobQueue.front();
        jobQueue.pop();

        cout << "Executing Job: " << job.name << " , Priority " << job.priority << endl;
    }
}

int evaluatePostFix(const string& postFix) {
    stack<int> stack;

    for (char ch : postFix) {
        if (isdigit(ch)) {
            stack.push(ch - '0');
        }
        else {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            int result;
            switch (ch) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '^':
                result = pow(operand1, operand2);
                break;
            default:
                throw runtime_error("Invalid operand encountered!");
            }

            stack.push(result);
        }
    }

    return stack.top();
}

std::string reverseString(const std::string& input) {
    // Create an empty stack of characters
    std::stack<char> charStack;

    // Push each character onto the stack
    for (char ch : input) {
        charStack.push(ch);
    }

    // Pop characters from the stack to obtain reversed string
    std::string reversedString;
    while (!charStack.empty()) {
        reversedString += charStack.top();
        charStack.pop();
    }

    return reversedString;
}

std::string reverseString_recursion(const std::string& input) {
    if (input.empty()) {
        return "";
    }
    return reverseString(input.substr(1)) + input[0];
}

int main()
{
    // BinarySearchTree Traversal:
    BinarySearchTree bst;
    Node* root = nullptr;
    root = bst.insert(root, 50);
    bst.insert(root, 30);
    bst.insert(root, 20);
    bst.insert(root, 40);
    bst.insert(root, 70);
    bst.insert(root, 60);
    bst.insert(root, 80);

    std::cout << "Post-order traversal: ";
    bst.postOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    bst.preOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    bst.inOrderTraversal(root);
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////

    // Evaluate postfix expression:
    std::string postfix = "523*+4-";
    int result = evaluatePostFix(postfix);
    std::cout << "Postfix expression: " << postfix << std::endl;
    std::cout << "Evaluation result: " << result << std::endl;
    ////////////////////////////////////////////////////////////////


    // Using a Stack to reverse a string:
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::string reversed = reverseString(input);
    std::cout << "Reversed string: " << reversed << std::endl;
    ////////////////////////////////////////////////////////////////

    return 0;
}
