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
        cout << value <<" Inserted ! " << endl;
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

int LinkedList::length() {
    int cnt = 0;
    if(isEmpty()) {
        return cnt;
    }
    Node* temp = head;
    while(temp) {
        cnt++;
        temp = temp->nextElement;
    }
    return cnt;
}

void LinkedList::reverse() {
    Node* prev = NULL;
    Node* curr = head;
    Node* nxt = NULL;

    while(curr) {
        nxt = curr->nextElement;
        curr->nextElement = prev;
        prev = curr;
        curr = nxt;
    }

    head = prev;
}

void LinkedList::insertLoop() {
    Node * temp = head;
    // traversing to get to last element of the list
    while (temp->nextElement != nullptr) {
        temp = temp->nextElement;
    }
    temp->nextElement = head; // pointing last element to head of the list
}

bool LinkedList::detectLoop() {
    Node* slow = head;
    Node* fast = head;
    while(slow && fast && fast->nextElement) {
        slow = slow->nextElement;
        fast = fast->nextElement->nextElement;
        if(slow == fast) {
            return true;
        }

    }
    return false;
}

int LinkedList::findMid() {
    int mid = (length() - 1)/2;

    Node* temp = head;
    int i = 0;
    while(i < mid) {
        temp = temp->nextElement;
        i++;
    }
    return temp==NULL ? 0 : temp->data;
}

void LinkedList::removeDuplicates() {
    Node * temp1, * temp2, * dup;
    temp1 = head;

    while(temp1 && temp1->nextElement) {
        temp2 = temp1;
        while(temp2->nextElement) {
            if(temp1->data == temp2->nextElement->data) {
                dup = temp2->nextElement;
                temp2->nextElement = temp2->nextElement->nextElement;
                delete dup;
            } else {
                temp2 = temp2->nextElement;
            }
        }
        temp1 = temp1->nextElement;
    }
}

void LinkedList::Union(LinkedList list1, LinkedList list2) {
    Node* temp1 = list1.getHead();
    while(temp1->nextElement) {
        temp1 = temp1->nextElement;
    }
    temp1->nextElement = list2.getHead();
    list1.removeDuplicates();
    list1.printList();
}

LinkedList LinkedList::Intersection(LinkedList list1, LinkedList list2) {
    Node* temp1 = list1.getHead();
    Node* temp2;
    LinkedList list3;

    while(temp1) {
        temp2 = list2.getHead();
        while(temp2){
            if(temp1->data == temp2->data) {
                list3.insertAtTail(temp1->data);
            }
            temp2 = temp2->nextElement;
        }
        temp1 = temp1->nextElement;
    }
    return list3;
}

int LinkedList::findNth(int n) {
    Node* p1 = head;
    int i = 0;
    while(i < 3) {
        p1 = p1->nextElement;
    }
    Node* p2 = head;

    while(p1 != NULL) {
        p2 = p2->nextElement;
        p1 = p1->nextElement;
    }

    return p2->data;
}