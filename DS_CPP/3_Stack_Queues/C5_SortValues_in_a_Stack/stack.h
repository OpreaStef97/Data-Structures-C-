#include <iostream>

using namespace std;

class myStack {
private:
    int* stackArr;
    int capacity;
    int numElements;
public:
    myStack(int size);
    bool isEmpty();
    int getTop();
    bool push(int value);
    int pop();
    int getSize();
    void showStack();
};