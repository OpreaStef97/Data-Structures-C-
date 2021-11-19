#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList list;
    for(int i = 12; i < 25; i++) {
        list.insertAtTail(i);
    }
    list.printList();

    cout << list.findMid() << endl;
}