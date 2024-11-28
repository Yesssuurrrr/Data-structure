#include <iostream>
#define MAX 1000
#include <climits>

class Queue {
    int front, rear, size;
    int capacity;
    int* array;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        front = size = 0;
        rear = capacity - 1;
        array = new int[this->capacity];
    }

    ~Queue() {
        delete[] array;
    }

    bool isFull() {
        return (size == capacity);
    }

    bool isEmpty() {
        return (size == 0);
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = item;
        size++;
        std::cout << item << " enqueued to queue\n";
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow\n";
            return INT_MIN;
        }
        int item = array[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int frontItem() {
        if (isEmpty())
            return INT_MIN;
        return array[front];
    }

    int rearItem() {
        if (isEmpty())
            return INT_MIN;
        return array[rear];
    }
};

int main() {
    Queue queue(1000);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    std::cout << queue.dequeue() << " dequeued from queue\n";

    std::cout << "Front item is " << queue.frontItem() << std::endl;
    std::cout << "Rear item is " << queue.rearItem() << std::endl;

    return 0;
}
