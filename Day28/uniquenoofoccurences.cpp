class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for (auto& num : arr) count[num]++;
        unordered_set<int> freq;
        for (auto& [v, f] : count) {
            if (freq.count(f) != 0) return false;
            freq.insert(f);
        }
        return true;
    }
};