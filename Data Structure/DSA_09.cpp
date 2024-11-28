#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node {
    string key;
    string value;
    Node* next;
};

// Dictionary class using a linked list
class Dictionary {
    Node* head;

public:
    Dictionary() {
        head = nullptr;
    }

    // Insert a key-value pair into the dictionary
    void insert(const string& key, const string& value) {
        Node* newNode = new Node();
        newNode->key = key;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
        cout << "Inserted (" << key << ", " << value << ") into the dictionary." << endl;
    }

    // Delete a key-value pair from the dictionary
    void remove(const string& key) {
        Node* temp = head;
        Node* prev = nullptr;

        // If the head node itself holds the key to be deleted
        if (temp != nullptr && temp->key == key) {
            head = temp->next;
            delete temp;
            cout << "Deleted key " << key << " from the dictionary." << endl;
            return;
        }

        // Search for the key to be deleted
        while (temp != nullptr && temp->key != key) {
            prev = temp;
            temp = temp->next;
        }

        // If the key was not present in the list
        if (temp == nullptr) {
            cout << "Key " << key << " not found in the dictionary." << endl;
            return;
        }

        // Unlink the node from the linked list
        prev->next = temp->next;
        delete temp;
        cout << "Deleted key " << key << " from the dictionary." << endl;
    }

    // Search for a value by key in the dictionary
    string search(const string& key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return "Key not found";
    }

    // Display all key-value pairs in the dictionary
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "(" << temp->key << ", " << temp->value << ") -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Destructor to clean up the memory
    ~Dictionary() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Dictionary dict;

    // Insert key-value pairs
    dict.insert("name", "Alice");
    dict.insert("age", "25");
    dict.insert("city", "New York");

    // Display the dictionary
    cout << "Dictionary contents:" << endl;
    dict.display();

    // Search for a key
    string key = "age";
    cout << "Search for key '" << key << "': " << dict.search(key) << endl;

    // Delete a key-value pair
    dict.remove("city");

    // Display the dictionary again
    cout << "Dictionary contents after deletion:" << endl;
    dict.display();

    return 0;
}
