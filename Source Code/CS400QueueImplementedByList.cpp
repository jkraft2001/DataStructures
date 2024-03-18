// CS400QueueImplementedByList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <queue>

template <typename T>
class Queue {
private:
    std::list<T> linkedList;

public:
    bool empty() const {
        return linkedList.empty();
    }

    int size() const {
        return linkedList.size();
    }

    void push(const T& item) {
        linkedList.push_back(item);
    }

    void pop() {
        if (!empty()) {
            linkedList.pop_front();
        }
    }

    T& front() {
        return linkedList.front();
    }

    T& back() {
        return linkedList.back();
    }
};

int main() {
    std::queue<int> queue;
    //Queue<int> queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);

    // access the front element of the queue
    std::cout << "Front: " << queue.front() << std::endl;//10

    // access the back element of the queue
    std::cout << "Back: " << queue.back() << std::endl;//30


    // check if the queue is empty
    bool isEmpty = queue.empty();
    std::cout << "Is queue empty? " << (isEmpty ? "Yes" : "No") << std::endl;

    // get the size of the queue
    std::cout << "Queue size: " << queue.size() << std::endl;//3

    // process elements in the queue
    while (!queue.empty()) {
        // access and remove the front element
        int element = queue.front();
        std::cout << "Processing element: " << element << std::endl;
        queue.pop();
    }

    // check if the queue is empty after poping
    isEmpty = queue.empty();
    std::cout << "Is queue empty? " << (isEmpty ? "Yes" : "No") << std::endl;


    return 0;
}

