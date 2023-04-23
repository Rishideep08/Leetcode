class Solution {
    private : int mod = 1e9+7;
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        if(n==0){
            return 0;
        }
        vector<int> dp(n+1,0);
        dp[n]  =1;
        
        for(int i=n-1;i>=0;i--){
            long long  sum = 0;
            for(int j=i;j<n;j++){
                sum= sum*10+(s[j]-'0');  
                if(sum <=k && sum>=1){
                    dp[i] = (dp[j+1]+dp[i])%mod;
                }else{
                    break;
                }
            }
        }
        return dp[0]%mod;
        
    }
};