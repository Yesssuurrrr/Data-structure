#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head != nullptr) {
        head->prev = newNode;
    }
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete a node with a given key
void deleteNode(Node*& head, int key) {
    Node* temp = head;

    // Find the node to be deleted
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }

    // If the key was not present in the list
    if (temp == nullptr) return;

    // If node to be deleted is the head node
    if (temp == head) {
        head = temp->next;
    }

    // Change next only if node to be deleted is NOT the last node
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    // Change prev only if node to be deleted is NOT the first node
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    delete temp;
}

// Function to traverse the linked list
void traverseList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert nodes
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtBeginning(head, 5);
    insertAtEnd(head, 30);

    // Traverse the list
    cout << "Doubly linked list after insertion:" << endl;
    traverseList(head);

    // Delete a node
    deleteNode(head, 20);

    // Traverse the list again
    cout << "Doubly linked list after deletion of 20:" << endl;
    traverseList(head);

    return 0;
}
