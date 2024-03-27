
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
         if(n==1){
            return true;
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum+= nums[i];
        }
        

        vector<vector<int>> dp(n,vector<int>(n,0)); 
        for(int i = 0; i < n; i++){
            dp[i][i] = nums[i];
        }
        for(int i = 0; i < n-1; i++){
            dp[i][i+1] = max(nums[i],nums[i+1]);
        }
    
        for(int diff = 2; diff < n; diff++){
           for(int i = 0,j=diff; i<n-2 && j <= n-1; i++,j++){
               dp[i][j] = nums[i] + min(dp[i+2][j],dp[i+1][j-1]);
               dp[i][j] = max(dp[i][j],nums[j] + min(dp[i][j-2],dp[i+1][j-1]));

           }
        }
        return dp[0][n-1]>=(sum-dp[0][n-1]);

    }
};