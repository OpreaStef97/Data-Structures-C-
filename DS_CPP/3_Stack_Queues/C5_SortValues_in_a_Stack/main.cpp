#include "stack.h"
#include <stack>

myStack sortStack(myStack s, int size) {
    myStack temp(size);

    while(!s.isEmpty()) {
        int val = s.getTop();
        s.pop();

        if(val >= temp.getTop()) {
            temp.push(val);
        }
        else {
            while(!temp.isEmpty()) {
                s.push(temp.getTop());
                temp.pop();
            }
            temp.push(val);
        }
    }
    return s;
}

stack<int> sortStack(stack<int> s) {
    stack<int> temp;

    while(!s.empty()) {
        int val = s.top();
        s.pop();

        if(temp.empty() || val >= temp.top()) {
            temp.push(val);
        }
        else {
            while(!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
            temp.push(val);
        }
    }

    while(!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
    return s;
}

//Recursive

void insert(stack<int> &stack, int val) {
    if(stack.empty() || val < stack.top()) {
        stack.push(val);
    } else {
        int tmp = stack.top();
        stack.pop();
        insert(stack,val);
        stack.push(tmp);
    }
}

void sort(stack<int> &stack) {
    if(stack.empty()) {
        return;
    }
    int val = stack.top();
    stack.pop();
    sort(stack);
    insert(stack,val);
}

int main() {

    stack<int> s;

    s.push(42);
    s.push(12);
    s.push(60);
    s.push(23);

    // s = sortStack(s);
    sort(s);
    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}