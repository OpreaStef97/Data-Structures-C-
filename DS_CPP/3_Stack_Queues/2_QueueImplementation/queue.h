#include <iostream>

class myQueue {
private:
    int* queueArr;
    int capacity;
    int numElements;
    int front;
    int back;
public:
    myQueue(int size);
    bool isEmpty();
    int getFront();
    void enqueue(int value);
    int dequeue();
    int getSize();
    void showqueue();
};