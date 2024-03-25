class Solution {
public:
    int function(vector<int>& nums){
        while(nums.size()!=1){
        int n=nums.size();
        vector<int> newNums(n-1);
        if (n==1) return nums[0];
        for(int i=0;i<n-1;++i){
            newNums[i]=(nums[i] + nums[i+1]) % 10;
        }
        nums.clear();
        for(auto x:newNums){
            nums.push_back(x);
        }
        function(nums);
        }
        return nums[0];
    }
    int triangularSum(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
         return function(nums);
    }
};