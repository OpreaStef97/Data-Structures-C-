#include <iostream>

using namespace std;

class twoStacks {

private:
    int size;
    int *arr;
    int top1, top2;
   
public:
    twoStacks(int n) {
        size = n;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
 
    void push1(int value) {
        if(top1 < top2 - 1) {
            arr[++top1] = value;
        } else {
            cout << "Stack full" << endl;
        }
    }
 
    void push2(int value) {
        if(top1 < top2 - 1) {
            arr[--top2] = value;
        } else {
            cout << "Stack FULL" << endl;
        }
    }

    int pop1() {
        if(top1 == -1) {
            return -1;
        }
        
        return arr[top1--];
    }

    int pop2() {
        if(top2 == size) {
            return -1;
        }

        return arr[top2++];
    }
};

int main(){
  
   twoStacks tS(5);
    tS.push1(11);
    tS.push1(3);
    tS.push1(7);
    tS.push2(1);
    tS.push2(9);
  
    cout << tS.pop1() << endl;
    cout << tS.pop2() << endl;
    cout << tS.pop2() << endl;
    cout << tS.pop2() << endl;
    cout << tS.pop1() << endl;

    return 0; 
}