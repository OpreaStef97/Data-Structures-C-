#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxR = 0;
        stack<int> st;
        heights.push_back(0);
        int n = heights.size();

        for(int i = 0; i < n; i++) {
            int elem = heights[i];
            while(!st.empty() && heights[st.top()] >= elem) {
                int h = heights[st.top()];
                st.pop();
                int w = i - (st.empty() ? -1 : st.top()) - 1;
                maxR = max(maxR, h * w);
            }
            st.push(i);
        }

        return maxR;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << s->largestRectangleArea(heights);

    delete s;
}