#include <vector>
#include <algorithm>
using namespace std;

class DSU {
public:
    vector<int> parent;
    DSU(int size) : parent(size) {
        for(int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2]; // Sort meetings by time
        });
        
        DSU dsu(n);
        // Initially, person 0 and firstPerson know the information
        dsu.unite(0, firstPerson);

        vector<int> tmp;
        int currentTime = -1;
        for (auto& meeting : meetings) {
            if (meeting[2] != currentTime) {
                // Update connections for the current time
                for (int person : tmp) {
                    if (dsu.find(person) != dsu.find(0)) {
                        dsu.parent[person] = person; // Disconnect if not connected to 0
                    }
                }
                tmp.clear();
                currentTime = meeting[2];
            }
            dsu.unite(meeting[0], meeting[1]);
            tmp.push_back(meeting[0]);
            tmp.push_back(meeting[1]);
        }

        // Final check for last batch of meetings
        for (int person : tmp) {
            if (dsu.find(person) != dsu.find(0)) {
                dsu.parent[person] = person; // Disconnect if not connected to 0
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (dsu.find(i) == dsu.find(0)) {
                result.push_back(i); // Person is informed
            }
        }

        return result;
    }
};
