class Solution {
public:
    vector<vector<int>> dp;
    int func(string s, int l, int r){
        if(l>r){
            return 0;
        }
        if(l==r){
            return 1;
        }
        
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        int ans = 1+func(s,l+1,r);
        for(int i=l+1;i<=r;i++){
            if(s[i] == s[l]){
                ans = min(ans,func(s,l,i-1)+func(s,i+1,r));
            }
        }
        dp[l][r] = ans;
        return ans;
    }
    
    int strangePrinter(string s) {
        int n = s.size();
        dp = vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return func(s,0,n-1);
    }
};