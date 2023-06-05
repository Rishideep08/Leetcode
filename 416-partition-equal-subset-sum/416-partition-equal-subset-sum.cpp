class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum = sum +nums[i];
        }
        if(sum %2 !=0){
            return false;
        }
        int halfVal= sum/2;
        // vector<vector<int>>dp(2,vector<int>(halfVal+1,0));
        vector<int> prev(halfVal+1,0);
        vector<int> curr(halfVal+1,0);
        // dp[0][0] = 1;
        prev[0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=halfVal;j++){
                curr[j] = prev[j];
                if(j>=nums[i-1]){
                    curr[j] = curr[j] || prev[j-nums[i-1]];
                }  
            }
            prev = curr;
            for(int j=0;j<=halfVal;j++){
                curr[0] = 0;
            }
        }
        return curr[halfVal]==1?true:false;
        
    }
};