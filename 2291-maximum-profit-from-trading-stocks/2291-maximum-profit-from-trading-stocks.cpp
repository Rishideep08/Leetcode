class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();
        vector<vector<int>> dp(n+1,vector<int>(budget+1,0));
        for(int i=1;i<=n;i++){
            if(future[i-1]-present[i-1]>0 && present[i-1]==0){
                dp[i][0] = max(dp[i-1][0],dp[i-1][0]+future[i-1]-present[i-1]);
            }else{
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int i=1;i<=n;i++){
            for(int b=1;b<=budget;b++){
                dp[i][b] = dp[i-1][b];
                if(b>=present[i-1] && future[i-1]>present[i-1]){
                    dp[i][b] = max(dp[i-1][b-present[i-1]]+future[i-1]-present[i-1],dp[i][b]);
                }
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int b=0;b<=budget;b++){
        //         cout<<dp[i][b]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        
        return dp[n][budget];
        
    }
};