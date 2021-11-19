#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> res(n);

    for(int i = n - 1; i >= 0; i--) {
        st.push(i);
    }

    for(int i = n - 1; i >= 0; i--) {
        int next = nums[i];

        while(!st.empty() && nums[st.top()] <= next) {
            st.pop();
        }

        res[i] = st.empty() ? -1 : nums[st.top()];

        st.push(i);
    }
    return res;

}

int main() {
    vector<int> nums = {7, 8, 12, 7, 2};

    for(auto e : nextGreaterElements(nums)) {
        cout << e << ' ';
    }
}