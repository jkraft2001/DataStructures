// CS400QueueByCircularLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    // constructor:
    CircularLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    // destructor:
    ~CircularLinkedList() {
        while (!isEmpty()) {
            removeFront();
        }
    }

    bool isEmpty() const {
        // TODO:
        return size == 0;
    }

    int getSize() const {
        // TODO:
        return size;
    }

    void addFront(const T& item) {
        // TODO:
        Node* newNode = new Node(item);

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }

        size++;
    }

    void addBack(const T& item) {
        // TODO:
        Node* newNode = new Node(item)

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }

        size++;
    }


    void removeFront() {
        // TODO:
        if (isEmpty()) {
            cout << "Cannot remove. List is empty." << endl;
        }
    }


    void removeBack() {
        // TODO:



    }


    void print() const {
        // TODO:




    }
};

// implement quque class using composition of circular linked list:
template <typename T>
class Queue {
    // TODO:



    
};

int main() {
    Queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.print();  // Output: 1 -> 2 -> 3

    queue.dequeue();
    queue.print();  // Output: 2 -> 3

    return 0;
}
