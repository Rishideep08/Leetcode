class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9+7;
        vector<int> dp(n,0);
        dp[0] = 1;
        int l1 = 0;
       
        unordered_map<int,int> um;
         um[nums[0]] = 0;
        for(int i=1;i<n;i++){
            if(um.find(nums[i]) == um.end()){
                um[nums[i]] = i;
            }else{
                int l2 = um[nums[i]];
                l1 = um[nums[i-1]];
                while(l2<l1){
                    l2 = min(l2,um[nums[l1]]);
                    l1--;
                }
                um[nums[i]] = min(l1,l2);
            }
            int j = um[nums[i]];
            if(j==0){
                dp[i] = 1;
            }else{
                dp[i] = (dp[j-1]%mod+dp[j-1]%mod)%mod;
            }
        }
            
            
        return dp[n-1]%mod;
    }
};