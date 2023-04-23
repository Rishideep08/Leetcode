class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[n] = 1;
        int mod = 1e9+7;
        for(int i=n-1;i>=0;i--){
            long long sum =0;
            for(int j=i;j<n;j++){
                sum = sum*10+(s[j]-'0');
                if(sum>=1 && sum<=k){
                    dp[i] = (dp[i]+dp[j+1])%mod;
                }else{
                    break;
                }
            }
        }
        
        return dp[0];
    }
};