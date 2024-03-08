#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[x] = y;
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        unordered_map<int, int> primeToIndex;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            for (int factor = 2; factor * factor <= num; ++factor) {
                if (num % factor == 0) {
                    if (!primeToIndex.count(factor)) {
                        primeToIndex[factor] = i;
                    } else {
                        unite(i, primeToIndex[factor]);
                    }
                    while (num % factor == 0) num /= factor;
                }
            }
            if (num > 1) { // num itself is a prime
                if (!primeToIndex.count(num)) {
                    primeToIndex[num] = i;
                } else {
                    unite(i, primeToIndex[num]);
                }
            }
        }

        int root = find(0);
        for (int i = 1; i < n; ++i) {
            if (find(i) != root) return false;
        }
        return true;
    }
};
