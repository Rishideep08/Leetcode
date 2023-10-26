class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int k=1;k<=n;k++){
            for(int i=0;i<n;i++){
                int j = i+k-1;
                if(j>=n){
                    break;
                }
                if(i==j){
                    dp[i][j] = 1;
                }else if(i == j-1 && s[i]==s[j]){
                    dp[i][j] = 1;
                }else if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int> dp1(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(dp[j][i] == 1 && i-j+1>=k){
                    // cout<<"Hi"<<endl;
                    if(j>0){
                        dp1[i] = max(dp1[i],dp1[j-1]+1);
                    }else{
                        dp1[i] = 1;
                    }
                }
            }
            if(i>0)
                dp1[i] = max(dp1[i],dp1[i-1]);
        }
        return dp1[n-1];
        // int ans = 0;
        // for(int i=0;i<n;i++){
        //     // cout<<dp1[i]<<" ";
        //     ans = max(ans,dp1[i]);
        // }
        // // cout<<endl;
        // return ans;
    }
};