class Solution {
public:
    int ans = 1;
    int left = 0;
    int right = 0;
    vector<vector<int>> dp;
    int fun(string &s,int i,int j){
        if(i>j){
            return 1;
        }
        if(i==j){
            return 1;
        }
        if(dp[i][j] !=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
           if(fun(s,i+1,j-1)){
               if(ans<j-i+1){
                   ans = j-i+1;
                   left = i;
                   right = j;
               }
               dp[i][j] = 1;
               return 1;
           }
        }
        fun(s,i,j-1);
        fun(s,i+1,j);
        dp[i][j] = 0;
        return 0;
    }
    string longestPalindrome(string s) {
        dp = vector<vector<int>>(s.size(),vector<int>(s.size(),-1));
        fun(s,0,s.size()-1);
        return s.substr(left,right-left+1);
    }
};