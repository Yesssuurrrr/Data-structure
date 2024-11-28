#include <iostream>
#define MAX 1000

class Stack {
    int top;

public:
    int a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        std::cout << "Stack Overflow\n";
        return false;
    } else {
        a[++top] = x;
        std::cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        std::cout << "Stack Underflow\n";
        return 0;
    } else {
        int x = a[top--];
        return x;
    }
}

int Stack::peek() {
    if (top < 0) {
        std::cout << "Stack is Empty\n";
        return 0;
    } else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << stack.pop() << " popped from stack\n";
    std::cout << "Top element is " << stack.peek() << std::endl;
    std::cout << "Elements present in stack: ";
    while (!stack.isEmpty()) {
        std::cout << stack.peek() << " ";
        stack.pop();
    }
    return 0;
}
