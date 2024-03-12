class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            int val=arr[i];
            if( val  > 0 && val <= n){
            int box=val-1;
            if(val != arr[box]){
                swap(arr[box],arr[i]);
                i--;
            }
            }
        }
        for(int i=0;i<n;i++)
            if(i+1!=arr[i]) return i+1;
        return n+1;
    }
};