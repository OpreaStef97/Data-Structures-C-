#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList list;
    for(int i = 0; i < 5; i++) {
        list.insertAtTail(i);
    }
    list.printList();

    list.insertLoop();

    cout << boolalpha << list.detectLoop() << endl;
}