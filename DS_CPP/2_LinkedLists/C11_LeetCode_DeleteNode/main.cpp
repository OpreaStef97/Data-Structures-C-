#include "LinkedList.h"

void deleteNode(Node* node) {
    Node* temp = node->nextElement;
    *node = *(temp);
    delete temp;
}

int main() {
    LinkedList l;

    for(int i = 1; i <= 4; i++) {
        l.insertAtTail(i);
    }

    Node* temp = l.getHead();

    temp = temp->nextElement->nextElement;

    deleteNode(temp);

    l.printList();
}