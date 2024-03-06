class Solution {
private:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = col;
        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - col, graph, color)) return false;
            } else if (color[neighbor] == col) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, graph, color)) return false;
            }
        }
        return true;
    }
};
