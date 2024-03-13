//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    private:
    void bfs(int row, int col, vector<vector<int>> &visit, vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        visit[row][col] = 1; // Mark as visited when pushing to queue

        // Directions: up, right, down, left
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while (!q.empty()) {
            auto [curRow, curCol] = q.front();
            q.pop();

            for (auto &dir : dirs) {
                int newRow = curRow + dir[0], newCol = curCol + dir[1];
                // Check for valid, unvisited land cell
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == '1' && !visit[newRow][newCol]) {
                    q.push({newRow, newCol});
                    visit[newRow][newCol] = 1; // Mark as visited when pushing to queue
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;
        vector<vector<int>> visit(n, vector<int>(m, 0));

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (!visit[row][col] && grid[row][col] == '1') {
                    bfs(row, col, visit, grid);
                    ++count; // Found an island
                }
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends