// CS400Re-arrangeLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
    //TODO:

};

typedef Node* NodePtr;

// Function to create a new node with the given data
NodePtr createNode(int data) {
    //TODO:


}

// Function to print the linked list
void printList(NodePtr head) {
    //TODO:


}

void rearrangeLinkedList(NodePtr& head) {
    //TODO:



}


// test your solution:
int main() {
    // Create the linked list: 1 -> 2 -> 5 -> 8 -> 3 -> 6 -> 7 -> 4
    NodePtr head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(5);
    head->next->next->next = createNode(8);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(4);

    // Print the original list
    std::cout << "Original List: ";
    printList(head);

    // Re-arrange the list
    rearrangeLinkedList(head);

    // Print the re-arranged list
    std::cout << "Re-arranged List: ";
    printList(head);

    // Clean up the memory
    NodePtr current = head;
    while (current != nullptr) {
        NodePtr temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

