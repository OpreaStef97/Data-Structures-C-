#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> stockSpanner(vector<int>& stock) {
        vector<int> res(stock.size(), 1);
        stack<int> stack;
        for(int i = 0; i < (int)stock.size(); ++i) {
            int elem = stock[i];
            while(!stack.empty() && stock[stack.top()] < elem) {
                res[i] += res[stack.top()];  
                stack.pop();
            }
            stack.push(i);
        }

        return res;
    }

};

int main() {
    vector<int> stock = {100, 80, 60, 70, 60, 75, 85};

    Solution *s = new Solution();

    for(auto e : s->stockSpanner(stock)) {
        cout << e << ' ';
    }

}