// CS400HW5Question2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// finish all TODOs and use conde from main() to test:

#include <iostream>
#include <queue>

void deleteThirdElement(std::queue<int>& q, int position) {
    if (q.size() < 3) {
        cout << "Queue has less than 3 elements. Cannot delete the third element." << endl;
        return;
    }

    // Temporary queue to hold the first two elements
    queue<int> tempQueue;

    // Push the first two elements into the temporary queue
    for (int i = 0; i < 2; ++i) {
        tempQueue.push(q.front());
        q.pop();
    }

    // Pop the third element (effectively deleting it)
    q.pop();

    // Push back the elements from the temporary queue to the original queue
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
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;

    // Delete the element at position 2 (0-based index)
    deleteThirdElement(myQueue, 2);

    std::cout << "Modified Queue: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;

    return 0;
}

