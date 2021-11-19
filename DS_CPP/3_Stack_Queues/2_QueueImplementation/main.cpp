#include "queue.h"

using namespace std;

int main() {

  myQueue queue(5);
  queue.enqueue(2);
  queue.enqueue(4);
  queue.enqueue(6);
  queue.enqueue(8);
  queue.enqueue(10);
  queue.showqueue();
  cout << "Adding 6th element to a queue with capacity equal to 5: " << endl;
  queue.enqueue(12);

  queue.showqueue();
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  queue.showqueue();
  cout << "The size of queue is: " << queue.getSize() << endl;
  queue.enqueue(14);
  queue.enqueue(16);
  queue.showqueue();
  cout << "The size of queue is: " << queue.getSize() << endl;

  return 0;
}