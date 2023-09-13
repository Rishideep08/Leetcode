class Solution {
public:
    vector<vector<int>>dp;
    int func(vector<int>&nums,int k,int start,int end){
        
        if(dp[start][k]!= -1){
            return dp[start][k];
        }
        int temp = INT_MAX;
        if(k == 0){            
            temp = nums[end]-nums[start-1];
        }else{
            for(int i=start;i<nums.size();i++){
                if(end-i>=k-1)
                    temp = min(temp,max(nums[i]-nums[start-1],func(nums,k-1,i+1,end)));
            }
        }
        // cout<<temp<<" "<<k<<" "<<start<<" "<<end<<endl;
        
        dp[start][k] = temp;
        // cout<<start<<" " <<k<<" "<<dp[start][k]<<endl;
        return dp[start][k];
        
    }
    int splitArray(vector<int>& nums, int k) {
        nums.insert(nums.begin(),0);
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i]+nums[i-1];
        }
        
        // for(int i=0;i<nums.size();i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        int n = nums.size();
        dp = vector<vector<int>>(n+1,vector<int>(k+1,-1));
        return func(nums,k-1,1,nums.size()-1);
    }
};