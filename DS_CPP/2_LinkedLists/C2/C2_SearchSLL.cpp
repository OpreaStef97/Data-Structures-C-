#include "LinkedList.h"

int main() {
    LinkedList list;

    for(int i = 0; i < 10; i++) {
        list.insertAtTail(rand()%10);
    }

    list.printList();

    cout<<list.search(14)<<endl;

    list.deleteHead();

    list.printList();
}