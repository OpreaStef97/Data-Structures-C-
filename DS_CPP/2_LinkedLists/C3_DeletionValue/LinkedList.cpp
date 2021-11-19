#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
}

Node* LinkedList::getHead() {
    return head;
}

bool LinkedList :: isEmpty() {
    if(head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

bool LinkedList::printList() {        // Printing the list
    if (isEmpty()) {
        cout << "List is Empty!";
        return false;
    }
    Node *temp = head;        // starting from head node
    cout << "List : ";

    while (temp != nullptr) {     // traveresing through the List
        cout << temp->data << "->"  ;
        temp = temp->nextElement;    // moving on to the temp's nextElement
    }
    cout  << "null " << endl;    // printing null at the end
    return true;
}

void LinkedList::insertAtHead(int value) {
    Node* newNode = new Node(value);
    
    newNode->nextElement = head;
    head = newNode;
    cout << value << " Inserted ! ";
}

void LinkedList::insertAtTail(int value) {
    // Enter your code here
    if(head == nullptr) {
        Node* newNode = new Node(value);
        head = newNode;
    } else {
        Node* newNode = new Node(value);
        Node* temp = head;

        while(temp->nextElement != nullptr) {
            temp = temp->nextElement;
        }

        temp->nextElement = newNode;
        newNode->nextElement = nullptr;
        
        cout << value <<" Inserted ! " << endl; 
    }
} 

bool LinkedList::search(int value) {
    if(head == NULL) {
        return false;
    }
    Node* temp = head;

    while(temp != nullptr) {
        if(temp->data == value) {
            return true;
        }
        temp = temp->nextElement;
    }
    return false;
}

bool LinkedList::deleteHead() {
    if(isEmpty()){
        cout << "List is empty";
        return false;
    }

    Node* currentNode = head;
    head = head->nextElement;
    delete currentNode;
    return true;
}

bool LinkedList::Delete(int value) {
    if(isEmpty()) {
        return false;
    }
    if(head->data == value) {
        return deleteHead();
    }
    Node* temp = head;
    while(temp->nextElement != nullptr) {
        if(temp->nextElement->data == value){
            break;
        }
        temp = temp->nextElement;
    }
    if(temp->nextElement) {
        Node* prev = temp;
        Node* curr = temp->nextElement;
        prev->nextElement = curr->nextElement;
        delete curr;
        return true;
    } else {
        cout << "Element not found!" << endl;
        return false;
    }
}