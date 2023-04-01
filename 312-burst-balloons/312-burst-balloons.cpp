class Solution {
public:
    int func(vector<int>&nums,int l,int r,vector<vector<int>> &dp){
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        if(l>r){
            dp[l][r] = 0;
            return 0;
        }

        if(l==r){
            int left_count =  nums[l]*nums[l-1]*nums[r+1];
            dp[l][r] = left_count;
            return left_count;
        }
        int left_count = 0;
        for(int i=l;i<=r;i++){
            left_count = max(left_count,nums[i]*nums[l-1]*nums[r+1]+func(nums,l,i-1,dp)+func(nums,i+1,r,dp));
        }
        dp[l][r] = left_count;
        return left_count;
    }
    int maxCoins(vector<int>& nums) {

        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        vector<vector<int>> dp(1000,vector<int>(1000,-1));
        return func(nums,1,nums.size()-2,dp);
    }
};