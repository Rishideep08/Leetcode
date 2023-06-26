class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        vector<int> ngv,nsv;
        
        stack<int> s1,s2;
        
        for(int i=nums.size()-1;i>=0;i--){
            while(!s1.empty() && nums[s1.top()]<nums[i]){
                s1.pop();
            }
            
            while(!s2.empty() && nums[s2.top()]>=nums[i]){
                s2.pop();
            }
            
            if(s1.empty()){
                ngv.push_back(-1);
            }else{
                ngv.push_back(s1.top());
            }
            
            if(s2.empty()){
                nsv.push_back(-1);
            }else{
                nsv.push_back(s2.top());
            }
            
            s1.push(i);
            s2.push(i);
        }
        
        reverse(nsv.begin(),nsv.end());
        reverse(ngv.begin(),ngv.end());
        int n = nums.size();
        vector<long long> dp(n,LONG_LONG_MAX);
        dp[0] = 0;
        
//         for(int i=0;i<nums.size();i++){
//             cout<<nsv[i]<<" ";
//         }
//         cout<<endl;
        
//         for(int i=0;i<nums.size();i++){
//             cout<<ngv[i]<<" ";
//         }
//         cout<<endl;
        for(int i=0;i<nums.size();i++){
            int x = nsv[i];
            int y = ngv[i];
            
            if(x !=-1){
                dp[x] = min(dp[x],dp[i]+costs[x]);
            }
            
            if(y != -1){
                dp[y] = min(dp[y],dp[i]+costs[y]);
            }
     
        }
        return dp[n-1];
        
    }
};