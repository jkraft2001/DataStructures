// CS400Spring2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <vector>


struct Node {
    int data;
    Node* next;
    
};




class LinkedList
{
private:
    int count;
    Node* begin;
    Node* makeNode(const int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }
public:
    LinkedList() :count{ 0 }, begin{ nullptr }{}
    ~LinkedList() {
        Node* del = begin;
        while (begin != nullptr) {
            begin = begin->next;
            delete del;
            del = begin;
        }
    }
    int size() const {
        return count;
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

    void insertAtBegin(const int value) {
        Node* newNode = makeNode(value);
        newNode->next = begin;
        begin = newNode;
        count++;
    }




    void insertAtEnd(const int value) {
        Node* newNode = makeNode(value);
        Node* cur = begin;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;

    }

    void insert(int pos, int value) {
        if (pos < 0 || pos > count) {
            throw std::out_of_range("position is out of rang");
        }
        Node* add = makeNode(value);
        if (pos == 0) {
            add->next = begin;
            begin = add;
        }
        else {
            Node* cur = begin;
            for (int i = 1; i < pos; i++) {
                cur = cur->next;
            }
            add->next = cur->next;
            cur->next = add;
        }
        count++;
    }

    void erase(int pos) {
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
    void print() const {
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











/*
int main()
{

    LinkedList list;
    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(2, 3);
    list.insert(3, 4);
    list.insert(4, 5);
    list.print(); // 1 2 3 4 5
    std::cout << list.size() << std::endl; // 5

    std::cout << list.getValue(3) << std::endl; // 4

    list.insert(3, 100);
    list.print(); // 1 2 3 100 4 5
    list.erase(0); // 2 3 100 4 5 
    list.erase(4); // 2 3 100 4 
    list.print(); // 2 3 100 4
    std::cout << list.size() << std::endl; // 4




    return 0;
}
*/
