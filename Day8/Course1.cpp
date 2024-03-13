#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create an adjacency list to represent course dependencies
        vector<vector<int>> adj(numCourses);
        for (const auto& prerequisite : prerequisites) {
            adj[prerequisite[0]].push_back(prerequisite[1]); // Use prerequisite[0] for first element
        }

        // Calculate the in-degree of each course (number of prerequisites)
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            for (auto neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        // Use a queue to perform topological sorting
        queue<int> q;
        // Push courses with no prerequisites (in-degree 0) into the queue
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process courses in topological order
        int coursesCompleted = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            coursesCompleted++;

            // Decrease in-degree of neighbors (courses that depend on the current course)
            for (auto neighbor : adj[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If all courses were completed, there are no cycles; otherwise, a cycle exists
        return coursesCompleted == numCourses;
    }
};
