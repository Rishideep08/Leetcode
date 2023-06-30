class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(2,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[1][j] = dp[0][j-1]+1;
                }else{
                    dp[1][j] = max(dp[0][j],dp[1][j-1]);
                }
            }
            dp[0] = dp[1];
            
        }
        
        return dp[1][m];
    }
};