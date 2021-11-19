#include<vector>
#include<iostream>
#include<queue>

using namespace std;



class Solution {
public:
    int canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i = 0; i < (int)prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            for(auto& nbr : adj[i]) {
                indegree[nbr]++;
            }
        }
        queue<int> Q;
        for(int i = 0; i < numCourses; i++) {
            if(!indegree[i]) {
                Q.push(i);
            }
        }

        int cnt = 0;
        while(!Q.empty()) {
            int node = Q.front();
            Q.pop();
            cnt++;
            cout << node << ' ';
            for(auto& nbr : adj[node]) {
                indegree[nbr]--;
                if(!indegree[nbr]) {
                    Q.push(nbr);
                }
            }
        }

        return cnt == numCourses;
    }
};


int main() {
    vector<vector<int>> prerequisites = {
        {1,4},
        {2,4},
        {3,1},
        {3,2},
    };

    Solution *s = new Solution();

    cout << s->canFinish(5,prerequisites) << endl;


}