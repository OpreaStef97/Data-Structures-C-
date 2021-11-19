#include "stack.h"
#include <stack>
#include <array>
#include <vector>

vector<int> nextGreaterElement(vector<int> arr) {
    vector<int> result(arr.size());
    stack<int> st;
    int next;
    for(int i = (int)arr.size() - 1; i >= 0; i--) {
        next = arr[i];
        while(!st.empty() && st.top() <= next) {
            st.pop();
        }

        result[i] = st.empty() ? -1 : st.top();

        st.push(next);
    }
    return result;
}

// vector<int> nextGreaterElement(vector<int> arr) {
//     vector<int> result(arr.size(), -1);
//     stack<int> st;
//     for(int i = 0; i < (int)arr.size(); i++) {
//         int next = arr[i];
//         while(!st.empty() && arr[st.top()] < next) {
//             result[st.top()] = next;
//             st.pop();
//         }
//         st.push(i);
//     }
//     return result;
// }


int main() {
    vector<int> arr= {4, 6, 3, 2, 8, 1};

    for(auto e : nextGreaterElement(arr)) {
        cout << e << ' ';
    }
    cout << endl;
}