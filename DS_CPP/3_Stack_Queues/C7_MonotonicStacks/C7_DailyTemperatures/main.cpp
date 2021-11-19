#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        int n = temperatures.size();
        stack<int> stack;
        for(int i = n - 1; i >= 0; i--) {
            int elem = temperatures[i];
            while(!stack.empty() && temperatures[stack.top()] <= elem) {
                stack.pop();
            }

            if(!stack.empty()) {
                res[i] = stack.top() - i;
            }

            stack.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 68, 72, 76, 73};

    Solution *s = new Solution();

    for(auto e : s->dailyTemperatures(temperatures)) {
        cout << e << ' ';
    }
}