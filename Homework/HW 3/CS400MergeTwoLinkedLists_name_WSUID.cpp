// CS400MergeTwoLinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
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




NodePtr mergeSortedLists(NodePtr list1, NodePtr list2) {
    //TODO:


    
}





// test your solution:
int main() {
    // Create the first linked list: 1->3->5->7
    NodePtr list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);
    list1->next->next->next = createNode(7);

    // Create the second linked list: 2->4->6->8
    NodePtr list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);
    list2->next->next->next = createNode(8);

    // Merge the two sorted lists
    NodePtr mergedList = mergeSortedLists(list1, list2);

    // Print the merged list
    printList(mergedList);

    // Clean up the memory
    NodePtr current = mergedList;
    while (current != nullptr) {
        NodePtr temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}


