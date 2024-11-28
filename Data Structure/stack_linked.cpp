#include <iostream>

class StackNode {
public:
    int data;
    StackNode* next;
};

StackNode* newNode(int data) {
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = nullptr;
    return stackNode;
}

int isEmpty(StackNode* root) {
    return !root;
}

void push(StackNode*& root, int data) {
    StackNode* stackNode = newNode(data);
    stackNode->next = root;
    root = stackNode;
    std::cout << data << " pushed into stack\n";
}

int pop(StackNode*& root) {
    if (isEmpty(root)) {
        std::cout << "Stack Underflow\n";
        return 0;
    }
    StackNode* temp = root;
    root = root->next;
    int popped = temp->data;
    delete temp;
    return popped;
}

int peek(StackNode* root) {
    if (isEmpty(root)) {
        std::cout << "Stack is Empty\n";
        return 0;
    }
    return root->data;
}

int main() {
    StackNode* root = nullptr;
    push(root, 10);
    push(root, 20);
    push(root, 30);
    std::cout << pop(root) << " popped from stack\n";
    std::cout << "Top element is " << peek(root) << std::endl;
    std::cout << "Elements present in stack: ";
    while (!isEmpty(root)) {
        std::cout << peek(root) << " ";
        pop(root);
    }
    return 0;

}
