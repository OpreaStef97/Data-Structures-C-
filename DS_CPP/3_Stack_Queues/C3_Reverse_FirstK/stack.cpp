#include "stack.h"
#include <cassert>

myStack::myStack(int size) {
    capacity = size;
    stackArr = new int[size];
    assert(stackArr != NULL);
    numElements = 0;
}

bool myStack::isEmpty() {
    return numElements == 0;
}

int myStack::getTop() {
    return numElements == 0 ? -1 : stackArr[numElements - 1];
}

bool myStack::push(int value) {
    if(numElements < capacity) {
        stackArr[numElements] = value;
        numElements++;
        return true;
    } else {
        cout << "Stack FULL" << endl;
        return false;
    }
}

int myStack::pop() {
    if(numElements == 0) {
        cout << "Stack Empty" << endl;
        return -1;
    } else {
        numElements--;
        return stackArr[numElements];
    }
}

int myStack::getSize() {
    return numElements;
}

void myStack::showStack() {
    int i = 0;
    while(i < numElements) {
        cout << '\t' << stackArr[numElements  - 1 - i];
        i++;
    }
    cout << '\n';
}