#include <iostream>

constexpr int CIRCLE_QUEUE_MAX_SIZE = 10;

class CircleQueue {
    int data[CIRCLE_QUEUE_MAX_SIZE];
    int front;
    int rear;
public:
    CircleQueue() : front{ 0 }, rear{ 0 } {}

    ~CircleQueue() noexcept {
        front = 0;
        rear = 0;
    }

    int length() const noexcept {
        return (CIRCLE_QUEUE_MAX_SIZE + rear - front) % CIRCLE_QUEUE_MAX_SIZE;
    }

    bool empty() const noexcept {
        return front == rear;
    }

    bool full() const noexcept {
        return front == (rear + 1) % CIRCLE_QUEUE_MAX_SIZE;
    }

    void push(int value) {
        data[rear] = value;
        rear = (rear + 1) % CIRCLE_QUEUE_MAX_SIZE;
    }

    int pop() {
        int headElem = data[front];
        front = (front + 1) % CIRCLE_QUEUE_MAX_SIZE;
        return headElem;
    }
};

int main() {
    CircleQueue queue;

    for (int i = 0; i < 10; ++i) {
        if (!queue.full()) {
            queue.push(i + 20);
        }
    }

    std::cout << "queue length is " << queue.length() << "\n";
    while (!queue.empty()) {
        int i = queue.pop();
        std::cout << i << " ";
    }

    std::cout << "\n";
    return 0;
}
