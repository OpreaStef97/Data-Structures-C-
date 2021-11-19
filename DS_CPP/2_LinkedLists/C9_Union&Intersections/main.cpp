#include "LinkedList.h"

int main() {
    LinkedList l1;
    LinkedList l2;

    for(int i = 0 ; i < 4; i++) {
        l1.insertAtTail(i);
    }
    for(int i = 2 ; i < 9; i++) {
        l2.insertAtTail(i);
    }

    // l1.Union(l1,l2);

    LinkedList l3 = l1.Intersection(l1,l2);

    l3.printList();

    return 0;
}