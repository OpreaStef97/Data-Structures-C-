#include "queue.h"
#include <cassert>

using namespace std;

myQueue::myQueue(int size) {
    capacity = size;
    queueArr = new int[size];
    assert(queueArr != NULL);
    numElements = 0;
    front = 0;
    back = -1;
}

bool myQueue::isEmpty() {
    return numElements == 0;
}

int myQueue::getFront() {
    if(isEmpty()) {
        cout << "Queue Empty" << endl;
        return -1;
    } else {
        return queueArr[front];
    }
}

void myQueue::enqueue(int value) {
    if(numElements == capacity) {
        cout << "Queue FULL" << endl;
        return;
    }

    if(back == capacity - 1) {
        back = -1;
    }
    queueArr[++back] = value;
    numElements++;
}

int myQueue::dequeue() {
    if(isEmpty()) {
        cout << "Queue Empty!" << endl;
        return -1;
    }

    int tmp = queueArr[front++];

    if(front == capacity) {
        front = 0;
    }
    numElements--;
    return tmp;
}

int myQueue::getSize() {
    return numElements;
}

void myQueue::showqueue() {
    int i = front;
    int count = 0;
    while(count != numElements) {
        cout << '\t' << queueArr[i%capacity];
        i++;
        count++;
    }
    cout << '\n';
}