#include <stack>
#include <vector>
#include <limits>
#include <iostream>


using namespace std;

class newStack {
    stack<int> stack, Minstack;
public:
    newStack() {}

    void push(int val) {
        stack.push(val);
        
        if(Minstack.empty() || val <= Minstack.top()) {
            Minstack.push(val);
        }
    }
    
    void pop() {
        if(stack.top() == Minstack.top()) {
            Minstack.pop();
        }
        stack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return Minstack.top();
    }
};

int main() {
    newStack *obj = new newStack();

    obj->push(-2);
    obj->push(0);
    obj->push(-3);

    cout << obj->getMin() << endl;

    obj->pop();

    cout << obj->top() << endl;

    cout << obj->getMin() << endl;
}