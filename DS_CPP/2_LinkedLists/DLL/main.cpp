#include <iostream>

using namespace std;

class DoublyLinkedList;

class Node{
public:
    int data;
    Node* nextElement;
    Node* prevElement;
    Node() : nextElement{NULL} , prevElement{NULL} {}
    Node(int value) : Node() {
        data = value;
    }
    friend class DoublyLinkedList;
};

class DoublyLinkedList {
private:
    /* data */
    Node* head;
public:
    DoublyLinkedList() : head{nullptr} {};

    bool isEmpty() {
        if(head == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    Node* getHead() {
        return head;
    }

    bool printList() {    // printing all elements of the list
        if (isEmpty()) {
            cout << "List is Empty!" << endl;
            return false;
        }
        Node *temp = head;   // temp points to head of the list
        cout << "List : ";

        while (temp != nullptr) {    // traverse through the list
            cout << temp->data << "->"  ;
            temp = temp->nextElement;
        }
        cout  << "null " << endl;
        return true;
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->data = value;
        newNode->prevElement = nullptr;
        newNode->nextElement = head;
        if(head != nullptr) {
            head->prevElement = newNode;
        }
        head = newNode;
        cout << value << " Inserted! ";
    }

    bool deleteAtHead() {
        bool deleted = false;
        if(isEmpty()) {
            cout << "List is Empty" << endl;
            return deleted;
        }
        head = head->nextElement;
        head->prevElement = nullptr;
        return true;
    }

    bool Delete(int value) {
        bool deleted = false;
        if(isEmpty()) {
            cout << "List is Empty" << endl;
            return deleted;
        }

        Node* currentNode = head;

        if(currentNode->data == value) {
            cout << value << " deleted!" << endl;
            return deleted = deleteAtHead();
        }

        while(currentNode != nullptr) {
            if(currentNode->data == value) {
                currentNode->prevElement->nextElement = currentNode->nextElement;

                if(currentNode->nextElement != nullptr) {
                    currentNode->nextElement->prevElement = currentNode->prevElement;
                }

                cout << value << " deleted!" << endl;

                return deleted = true;
            }
            currentNode = currentNode->nextElement;
        }

        if(deleted == false) {
            cout << value << " does not exist!" << endl;
        }
        return deleted;
    }
};


int main() {
    DoublyLinkedList list;
    for(int i=1; i<=5; i++) {
        list.insertAtHead(i);      // inserting data in list
        list.printList();
    }

    list.Delete(1);    // deleting 1 from the list
    list.printList();

    list.Delete(5);    // deleting 5 from the list
    list.printList();

    list.Delete(3);    // deleting 3 from the list
    list.printList();

    list.Delete(12);
    list.printList();



    return 0;
}