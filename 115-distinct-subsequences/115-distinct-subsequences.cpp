class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size();
        int m = s.size();
        vector<vector<unsigned long long int>> dp(n,vector<unsigned long long int>(m,0));

        if(s[0] == t[0]){
            dp[0][0] = 1;
        }
        for(int i=1;i<m;i++){
          if(s[i] == t[0]){
              dp[0][i] = dp[0][i-1]+1;
          }else{
              dp[0][i] = dp[0][i-1];
          }
        }

        for(int i=1;i<n;i++){
            for(int j=i;j<m;j++){
                dp[i][j] = dp[i][j-1];
                if(t[i] == s[j]){
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};