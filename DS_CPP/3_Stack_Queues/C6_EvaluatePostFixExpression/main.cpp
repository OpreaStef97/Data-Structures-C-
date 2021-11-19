#include "stack.h"
#include <string>
#include <stack>
#include <math.h>

int evaluatePostFix(string exp) {
    myStack numStack(exp.size());
    for(auto& c : exp) {
        if(c >= '0' && c <= '9') {
            numStack.push(c-'0');
        } else {
            int tempR = numStack.getTop();
            numStack.pop();
            if(c == '*')
                tempR = numStack.getTop() * tempR;
            else if(c == '/')
                tempR = numStack.getTop() / tempR;
            else if(c == '+')
                tempR = numStack.getTop() + tempR;
            else if(c == '-')
                tempR = numStack.getTop() - tempR;
            numStack.pop();
            numStack.push(tempR);
        }
    }
    return numStack.getTop();
} 

int main() {
    string str = "921*-8-4+";

    cout << evaluatePostFix(str) << endl;
}
