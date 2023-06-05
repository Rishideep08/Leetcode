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
        vector<vector<int>>dp(n+1,vector<int>(halfVal+1,0));
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=halfVal;j++){
                dp[i][j] = dp[i-1][j];
                if(j>=nums[i-1]){
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][halfVal]==1?true:false;
        
    }
};