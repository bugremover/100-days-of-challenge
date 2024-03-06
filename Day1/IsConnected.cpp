class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        // Create a disjoint set data structure to represent connectivity
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0); // Initialize each node as its own parent

        // Helper function to find the root of the set to which a node belongs
        function<int(int)> find = [&](int u) {
            return (parent[u] == u) ? u : parent[u] = find(parent[u]);
        };

        // Union function to merge two sets
        auto unite = [&](int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu != pv) parent[pu] = pv;
        };

        // Function to check if two nodes are connected
        auto isConnected = [&](int u, int v) {
            return find(u) == find(v);
        };

        // Build edges based on the threshold condition
        for (int i = threshold + 1; i <= n; i++) {
            for (int j = i * 2; j <= n; j += i) {
                unite(i, j);
            }
        }

        // Process queries
        vector<bool> result;
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            result.push_back(isConnected(u, v));
        }

        return result;
    }
};
