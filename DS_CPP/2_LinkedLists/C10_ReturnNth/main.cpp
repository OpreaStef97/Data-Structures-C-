#include "LinkedList.h"

int main() {
    LinkedList l1;
    l1.insertAtTail(57);
    l1.insertAtTail(36);
    l1.insertAtTail(89);
    l1.insertAtTail(44);
    l1.insertAtTail(66);
    l1.insertAtTail(99);
    l1.insertAtTail(88);
    l1.insertAtTail(83);

    l1.printList();

    cout << l1.findNth(0) << endl;

    return 0;
}