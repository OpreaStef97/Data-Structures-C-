#include "stack.h"
#include <stack>

class newQueue {
private:
    stack<int> q1;
    stack<int> q2;
public:
    //Inserts Element in the Queue
    newQueue() {}

    void enQueue(int value) {
        // Write your code here 
        while(!q1.empty()) {
            int tmp = q1.top();
            q1.pop();
            q2.push(tmp);
        }

        q1.push(value);

        while(!q2.empty()) {
            int tmp = q2.top();
            q2.pop();
            q1.push(tmp);
        }

    }
    //Removes and Returns Element From Queue
    int deQueue() {
        if(q1.empty()) {
            return -1;
        } else {
            int tmp = q1.top();
            q1.pop();
            return tmp;
        }
    }

};

int main() {
    newQueue queue;
    
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);
    queue.enQueue(5);
  
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    return 0;
}