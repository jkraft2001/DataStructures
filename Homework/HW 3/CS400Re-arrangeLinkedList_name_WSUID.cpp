// CS400Re-arrangeLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

typedef Node* NodePtr;

// Function to create a new node with the given data
NodePtr createNode(int data) {
    return new Node(data);
}

// Function to print the linked list
void printList(NodePtr head) {
    NodePtr current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to merge two sorted linked lists
NodePtr mergeSortedLists(NodePtr l1, NodePtr l2) {
    Node dummy(0); // Dummy node to ease the handling of merged list
    NodePtr tail = &dummy; // Tail points to the dummy node initially

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next; // Move tail to the last node
    }

    // Attach the remaining elements of the non-empty list
    tail->next = (l1 != nullptr) ? l1 : l2;

    return dummy.next; // Return the merged list starting from the next of dummy node
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

