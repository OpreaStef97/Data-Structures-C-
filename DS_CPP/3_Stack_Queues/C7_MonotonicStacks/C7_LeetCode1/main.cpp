#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    int next;
    unordered_map<int,int> mp;

    for(int i = (int)nums2.size() - 1; i >= 0; i--) {
        next = nums2[i];

        while(!s.empty() && s.top() <= next) {
            s.pop();
        }

        if(!s.empty()) {
            mp[nums2[i]] = s.top();
        } else {
            mp[nums2[i]] = -1;
        }
        s.push(next);
    }
    vector<int> result(nums1.size());
    for(int i = 0; i < (int)nums1.size(); i++) {
        result[i] = mp[nums1[i]];
    }
    return result;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    for(auto e : nextGreaterElement(nums1, nums2)) {
        cout << e << ' ';
    }
    cout << endl;
}