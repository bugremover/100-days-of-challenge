#include <vector>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> nums3;

        int left = 0, right = 0;
        while (left < m && right < n) {
            if (nums1[left] <= nums2[right]) {
                nums3.push_back(nums1[left]);
                left++;
            } else {
                nums3.push_back(nums2[right]);
                right++;
            }
        }

        // Add remaining elements from nums1 and nums2
        while (left < m) {
            nums3.push_back(nums1[left]);
            left++;
        }

        while (right < n) {
            nums3.push_back(nums2[right]);
            right++;
        }

        int total = m + n;
        int half = total / 2;
        if (total % 2 == 0) {
            return (nums3[half - 1] + nums3[half]) / 2.0;
        } else {
            return nums3[half];
        }
    }
};