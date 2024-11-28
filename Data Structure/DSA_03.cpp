#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = newNode; // Point to itself, making it circular
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// Function to insert a node at the end
void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to delete a node with a given key
void deleteNode(Node*& head, int key) {
    if (head == nullptr) return;

    Node* temp = head;
    Node* prev = nullptr;

    // If the head node itself holds the key to be deleted
    if (temp->data == key && temp->next == head) {
        delete temp;
        head = nullptr;
        return;
    }

    // Find the node to be deleted
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->data != key);

    // If the key was not present in the list
    if (temp->data != key) return;

    // If more than one node in the list
    if (temp == head) {
        prev = head;
        while (prev->next != head) {
            prev = prev->next;
        }
        head = temp->next;
        prev->next = head;
        delete temp;
    } else if (temp->next == head) {
        prev->next = head;
        delete temp;
    } else {
        prev->next = temp->next;
        delete temp;
    }
}

// Function to traverse the circular linked list
void traverseList(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "head" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert nodes
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtBeginning(head, 5);
    insertAtEnd(head, 30);

    // Traverse the list
    cout << "Circular linked list after insertion:" << endl;
    traverseList(head);

    // Delete a node
    deleteNode(head, 20);

    // Traverse the list again
    cout << "Circular linked list after deletion of 20:" << endl;
    traverseList(head);

    return 0;
}
