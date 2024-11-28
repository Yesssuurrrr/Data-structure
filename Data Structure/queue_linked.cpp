#include <iostream>
#include <climits>

class QueueNode {
public:
    int data;
    QueueNode* next;

    QueueNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
    QueueNode *front, *rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void enqueue(int item) {
        QueueNode* temp = new QueueNode(item);
        if (rear == nullptr) {
            front = rear = temp;
            std::cout << item << " enqueued to queue\n";
            return;
        }
        rear->next = temp;
        rear = temp;
        std::cout << item << " enqueued to queue\n";
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow\n";
            return INT_MIN;
        }
        QueueNode* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        int item = temp->data;
        delete temp;
        return item;
    }

    int frontItem() {
        if (isEmpty())
            return INT_MIN;
        return front->data;
    }

    int rearItem() {
        if (isEmpty())
            return INT_MIN;
        return rear->data;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    std::cout << queue.dequeue() << " dequeued from queue\n";

    std::cout << "Front item is " << queue.frontItem() << std::endl;
    std::cout << "Rear item is " << queue.rearItem() << std::endl;

    return 0;
}
