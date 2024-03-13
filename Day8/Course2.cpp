#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(N); // Use vector<vector<int>> for adjacency lists
        for(auto& it : prerequisites) {
            // Directed graph, prerequisites are given in reverse order
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> indegree(N, 0); // Use vector for indegree for dynamic size
        for(int i = 0; i < N; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < N; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        if(topo.size() == N) return topo; // If all nodes are included in topo sort, return it
        return {}; // Otherwise, return an empty array indicating it's impossible to complete all courses
    }
};
