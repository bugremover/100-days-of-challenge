class Solution {
public:
    void solve(vector<int>& arr,vector<int>& v,  int target, int index,vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(v);
            return ;
        }
        if(target < 0){
            return ;
        }
        for(int i = index; i < arr.size(); i++){
            v.push_back(arr[i]);
            solve(arr,v,target - arr[i], i,ans);
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> v; 
        int index = 0 ;
        solve(arr,v,target,index,ans);
        return ans;
    }
};