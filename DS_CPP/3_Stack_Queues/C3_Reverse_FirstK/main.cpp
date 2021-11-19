#include <iostream>
#include "queue.h"
#include "stack.h"

using namespace std;

myQueue reverseK(myQueue queue, int k) {
    if(!queue.isEmpty()) {
        myStack stack(k);
        int cnt = 0;
        while(cnt < k) {
            stack.push(queue.getFront());
            queue.dequeue();
            cnt++;
        }

        while(!stack.isEmpty()) {
            queue.enqueue(stack.getTop());
            stack.pop();
        }

        for(int i = 0; i < queue.getSize() - k; i++) {
            int tmp = queue.getFront();
            queue.dequeue();
            queue.enqueue(tmp);
        }
    }
    return queue;
}

int main() {
    myQueue q(10);
    for(int i = 1; i <= 10; i++) {
        q.enqueue(i);
    }

    q.showqueue();

    myQueue p = reverseK(q, 5);

    p.showqueue();

}