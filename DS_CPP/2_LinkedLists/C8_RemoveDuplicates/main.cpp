#include "LinkedList.h"

int main() {
    LinkedList list;
    list.insertAtTail(1);
    list.insertAtTail(1);
    list.insertAtTail(2);

    list.removeDuplicates();

    list.printList();
}