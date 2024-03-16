#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        int max_length = 0;
        int running_sum = 0;
        map[0] = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            running_sum += nums[i] == 0 ? -1 : 1;
            if (map.find(running_sum) != map.end()) {
                max_length = max(max_length, i - map[running_sum]);
            } else {
                map[running_sum] = i;
            }
        }
        
        return max_length;
    }
};
