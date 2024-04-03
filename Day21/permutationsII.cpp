class Solution {
public:
    using int2 = pair<int, int>;
    int n0, sz;
    vector<int2> nWm;
    vector<vector<int>> result;

    void backtrack(vector<int>& subset, vector<int2>& freq) {
        if (subset.size() == n0) {
            result.push_back(subset);
            return;
        }

        for (int i = 0; i < sz; i++) {
            if (freq[i].second > 0) {
                subset.push_back(nWm[i].first);
                freq[i].second--;
                backtrack(subset, freq);
                subset.pop_back();
                freq[i].second++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nWm.push_back({ nums[0], 1 });
        int idx = 0;
        n0 = nums.size();
        for (int i = 1; i < n0; i++) {
            if (nums[i] == nums[i-1])
                nWm[idx].second++;
            else {
                nWm.push_back({ nums[i], 1 });
                idx++;
            }
        }
        sz=++idx;

        vector<int> subset;
        backtrack(subset, nWm);
        return result;
    }
};