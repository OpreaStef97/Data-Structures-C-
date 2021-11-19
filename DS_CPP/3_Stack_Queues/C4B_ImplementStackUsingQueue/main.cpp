#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> q;
    int size;
public:
    MyStack() {
        size = 0;
    }
    
    void push(int x) {        
        if(q.empty()) {
            q.push(x);
            size++;
            return;
        } else {
            q.push(x);
            int i = 0;
            while(i < size) {
                int tmp = q.front();
                q.pop();
                q.push(tmp);
                i++;
            }
            size++;
        }
    }
    
    int pop() {
        if(q.empty()) return {};
        int tmp = q.front();
        q.pop();
        return tmp;
    }
    
    int top() {
        return q.empty() == 1 ? int{} : q.front();
    }
    
    bool empty() {
        return q.empty() == 1;
    }
};


int main() {
    int x = 1;
    MyStack* obj = new MyStack();
    obj->push(x);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
}