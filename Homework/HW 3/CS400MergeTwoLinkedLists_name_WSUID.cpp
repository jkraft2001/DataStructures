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

// Function to rearrange the linked list such that odd numbers appear before even numbers
NodePtr rearrangeLinkedList(NodePtr head) {
    // If the list is empty or contains only one node, no rearrangement is needed
    if (head == nullptr || head->next == nullptr)
        return head;

    NodePtr oddHead = nullptr; // Head of the odd numbers list
    NodePtr evenHead = nullptr; // Head of the even numbers list
    NodePtr oddTail = nullptr; // Tail of the odd numbers list
    NodePtr evenTail = nullptr; // Tail of the even numbers list

    NodePtr current = head;

    while (current != nullptr) {
        if (current->data % 2 == 0) { // Even number
            if (evenHead == nullptr) {
                evenHead = current;
                evenTail = current;
            }
            else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        }
        else { // Odd number
            if (oddHead == nullptr) {
                oddHead = current;
                oddTail = current;
            }
            else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }
        current = current->next;
    }

    // Connect the odd list with the even list
    if (oddTail != nullptr)
        oddTail->next = evenHead;
    if (evenTail != nullptr)
        evenTail->next = nullptr; // Terminate the even list

    // Return the head of the rearranged list
    return (oddHead != nullptr) ? oddHead : evenHead;
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


