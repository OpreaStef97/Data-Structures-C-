#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool isBalanced(const string& exp) {
    stack<int> s;
    for(const auto& c : exp) {
        if(c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else {
            if(c == ')' && (s.empty() || s.top() != '(')) {
                return false;
            }
            else if(c == ')') {
                s.pop();
            }
            if(c == ']' && (s.empty() || s.top() != '[')) {
                return false;
            }
            else if(c == ']'){
                s.pop();
            }
            if(c == '}' && (s.empty() || s.top() != '{')) {
                return false;
            }
            else if(c == '}'){
                s.pop();
            }
        }
    }
    return true;
}

int main() {
    cout << isBalanced("][({})]}") << endl;
}