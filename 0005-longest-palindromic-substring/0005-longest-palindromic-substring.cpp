class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int left = 0;
        int right = 0;
        for(int k=1;k<=n;k++){
            for(int i=0;i<n;i++){
                int j = i+k-1;
                if(j>=n){
                    break;
                }
                if(i == j){
                    dp[i][j] = 1;
                }
                else if(i==j-1 && s[i] == s[j]){
                    dp[i][j] = 1;
                }
                else if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                
                if(dp[i][j] == 1){
                    left = i;
                    right = j;
                }
            }
        }
        
        return s.substr(left,right-left+1);
    }
};