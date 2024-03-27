// CS400HW5Question3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// finish all TODOs and use conde from main() to test:

#include <iostream>
#include <queue>

using namespace std;

void deleteMiddleElement(queue<int>& q, int position) {
    if (position < 0 || position >= q.size()) {
        cout << "Invalid position!" << endl;
        return;
    }

    queue<int> tempQueue;

    // Dequeue elements from the original queue until the element to be deleted is reached
    for (int i = 0; i < position; ++i) {
        tempQueue.push(q.front());
        q.pop();
    }

    // Skip dequeuing the element to be deleted
    q.pop();

    // Enqueue elements back from the temporary queue to the original queue
    while (!tempQueue.empty()) {
        q.push(tempQueue.front());
        tempQueue.pop();
    }
}

int main() {
    std::queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);

    std::cout << "Original Queue: ";
    for (queue<int> temp = myQueue; !temp.empty(); temp.pop())
        std::cout << temp.front() << " ";
    std::cout << std::endl;

    // Delete the element at position 2 (0-based index)
    deleteMiddleElement(myQueue, 2);

    std::cout << "Modified Queue: ";
    for (queue<int> temp = myQueue; !temp.empty(); temp.pop())
        std::cout << temp.front() << " ";
    std::cout << std::endl;

    return 0;
}

