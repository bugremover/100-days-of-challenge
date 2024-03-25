#include <vector>
#include <map>

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> countMap; 
        vector<int> result;

   
        for (int num : nums) {
            ++countMap[num];
        }

        
        for (const auto& pair : countMap) {
            if (pair.second == 2) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};
