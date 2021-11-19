#include "stack.h"

int main() {
    myStack s(10);
    cout << "\ns.top(): " << s.getTop();

    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 

    cout << "\nThe stack is: ";
    s.showStack();
    cout << "\ns.top(): " << s.getTop();
    cout << "\ns.pop(): " << s.pop() << endl;
    cout << "\ns.pop(): " << s.pop() << endl;
    cout << "\ns.pop(): " << s.pop() << endl;
    cout << "\ns.pop(): " << s.pop() << endl;

    s.push(23);
    s.push(57);
    s.push(17);
    s.push(29);
    s.push(6);
    s.push(7);
    s.push(12);
    s.push(19);

    cout << "\nThe stack is: ";
    
    s.showStack();
    cout << "\ns.pop(): " << s.pop() << endl;
    cout << "s.pop(): " << s.pop() << endl;
    cout << "The stack size is: " << s.getSize() << endl;
    return 0;
}