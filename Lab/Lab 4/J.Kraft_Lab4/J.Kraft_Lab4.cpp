#include <iostream>

using namespace std;

// Node class represents each element in the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize data, next, and prev pointers
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// DoublyLinkedList class represents the doubly linked list
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize head and tail pointers
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to deallocate memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Add an element at the beginning of the list
    void addFront(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Add an element at the end of the list
    void addBack(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Remove the first element from the list
    void removeFront() {
        if (!head)
            return;

        Node* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete temp;
    }

    // Remove the last element from the list
    void removeBack() {
        if (!tail)
            return;

        Node* temp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        delete temp;
    }

    // Traverse the list forward and print out all the elements
    void printForward() {
        Node* current = head;
        while (current) {
            cout << current->data;
            if (current->next)
                cout << "->";
            current = current->next;
        }
        cout << "->null" << endl;
    }

    // Traverse the list backward and print out all the elements
    void printBackward() {
        Node* current = tail;
        while (current) {
            cout << current->data;
            if (current->prev)
                cout << "->";
            current = current->prev;
        }
        cout << "->null" << endl;
    }
};

/*
int main() {
    DoublyLinkedList dll;
    dll.addFront(1);
    dll.addFront(2);
    dll.addFront(3);
    dll.addBack(4);
    dll.printForward(); // 3->2->1->4->null
    dll.printBackward(); // 4->1->2->3->null

    return 0;
}
*/
