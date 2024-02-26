#include <iostream>
#include <stdexcept>
#include <vector>


struct Node {
    int data;
    Node* next;
    Node* prev;

};


class DoublyLinkedList {
private:
    int count;
    Node* begin;
    Node* prev;
    Node* makeNode(const int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }
public:
    DoublyLinkedList() :count{ 0 }, begin{ nullptr } {}
    ~DoublyLinkedList() {
        Node* del = begin;
        while (begin != nullptr) {
            begin = begin->next;
            delete del;
            del = begin;
        }
    }


    bool empty() const {
        return (count == 0);
    }

    int getValue(int pos) const {
        if (pos < 0 || pos > count) {
            throw std::out_of_range("position is out of rang");
        }
        else if (pos == 0) {
            return begin->data;
        }
        else {
            Node* cur = begin;
            for (int i = 0; i < pos; i++) {
                cur = cur->next;
            }
            return cur->data;

        }
    }

    void addFront(Node* cur, int value) {
        // create a new node with given data
        Node* new_node = new Node* ();
        new_node->data = value;

        // assign previous pointer to NULL
        new_node->prev = NULL;

        // assign next pointer to the current head node
        new_node->next = (*cur);

        // if the list is not empty, set the current head's previous pointer to new node
        if ((*cur) != NULL) {
            (*cur)->prev = new_node;
        }

        // point the head to the new node
        (*cur) = new_node;

        return;
    }




    void addBack(const int value) {
        Node* newNode = makeNode(value);
        Node* cur = begin;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;

    }


    void removeFront(int pos) {
        if (pos < 0 || pos > count) {
            throw std::out_of_range("position is out of rang");
        }
        if (pos == 0) {
            Node* del = begin;
            begin = begin->next;
            delete del;
        }
        else {
            Node* cur = begin;
            for (int i = 0; i < pos - 1; i++) {
                cur = cur->next;
            }
            Node* del = cur->next;
            cur->next = cur->next->next;
            delete del;
        }
        count--;
    }


    void removeBack(int pos) {
        if (pos < 0 || pos > count) {
            throw std::out_of_range("position is out of rang");
        }
        if (pos == 0) {
            Node* del = begin;
            begin = begin->next;
            delete del;
        }
        else {
            Node* cur = begin;
            for (int i = 0; i < pos - 1; i++) {
                cur = cur->next;
            }
            Node* del = cur->next;
            cur->next = cur->next->next;
            delete del;
        }
        count--;
    }


    // traverse the list print out all the elements:
    void printForward() const {
        if (empty()) {
            std::cout << "List is empty!" << std::endl;
        }
        Node* cur = begin;
        while (cur != nullptr) {
            std::cout << cur->data << std::endl;
            cur = cur->next;
        }
    }


    void printBackward() const {
        if (empty()) {
            std::cout << "List is empty!" << std::endl;
        }
        Node* cur = begin;
        while (cur != nullptr) {
            std::cout << cur->data << std::endl;
            cur = cur->next;
        }
    }
};
