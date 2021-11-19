#include "LinkedList.h"

int main() {
    LinkedList list;

    for(int i = 0; i < 10; i++) {
        list.insertAtTail(i);
    }
    list.printList();

    list.reverse();

    list.printList();

    cout << list.length();
}