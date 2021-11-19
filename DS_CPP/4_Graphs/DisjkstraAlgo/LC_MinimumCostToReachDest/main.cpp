#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fee) {
        int n = fee.size();
        vector<vector<vector<int>>> adj(n);

        for(int i = 0; i < (int)edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int t = edges[i][2];

            adj[u].push_back({v, t, fee[u]});
            adj[v].push_back({u, t, fee[v]});
        }

        vector<int> cost(n, INT_MAX);
        vector<int> time(n, INT_MAX);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        cost[0] = fee[0];
        time[0] = 0;

        pq.push({cost[0], time[0], 0});

        while(!pq.empty()) {
            int c = pq.top()[0];
            int t = pq.top()[1];
            int u = pq.top()[2];

            pq.pop();

            for (int i = 0; i < (int)adj[u].size(); i++) {
                int v = adj[u][i][0];
                int tv = adj[u][i][1];
                int cv = adj[u][i][2];
                
			    // if this edge does not cause the time to exceed maxTime
                if (t + tv <= maxTime) {
                    
				    // if cost will decrease
                    if (cost[v] > c + cv) {
                        
                        cost[v] = c + cv;
                        time[v] = t + tv;
                        pq.push({cost[v], time[v], v});
                    }
                    
					// if time will decrease
                    else if (time[v] > t + tv) {
                        time[v] = t + tv;
                        pq.push({c + cv, time[v], v});
                    }
                }
            }
        }
        return cost[n-1];
    }
};


int main() {
    int maxTime = 30;
    vector<vector<int>> edges = {
        {0,1, 10},
        {1,2, 10},
        {2,5, 10},
        {0,3, 1},
        {3,4, 10},
        {4,5, 15},
    };

    vector<int> fees = {5,1,2,20,20,3};

    Solution* s = new Solution();

    cout << s->minCost(maxTime, edges, fees) << endl;
}