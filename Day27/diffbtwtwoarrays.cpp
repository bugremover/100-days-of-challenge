class Solution {
public:
    vector<int> solve(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> onlyInNums1;
        unordered_set<int> existsInNums2;

        for (int num : nums2) {
            existsInNums2.insert(num);
        }

        for (int num : nums1) {
            if (existsInNums2.find(num) == existsInNums2.end()) {
                onlyInNums1.insert(num);
            }
        }
        return vector<int> (onlyInNums1.begin(), onlyInNums1.end());
    }
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {solve(nums1, nums2), solve(nums2, nums1)};
    }
};