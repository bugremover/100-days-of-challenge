#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int left = 0, right = height.size() - 1; 
        int maxLeft = height[left], maxRight = height[right]; 
        int trappedWater = 0;

        while (left < right) {
            if (maxLeft < maxRight) {
                
                left++;
                maxLeft = max(maxLeft, height[left]);
                trappedWater += maxLeft - height[left];
            } else {
                
                right--;
                maxRight = max(maxRight, height[right]);
                trappedWater += maxRight - height[right];
            }
        }

        return trappedWater;
    }
};
