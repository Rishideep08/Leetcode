class Solution {
public:
    vector<vector<int>> dp;
    int func(string s,string p,int i,int j){

        if(i<s.size() &&j==p.size()){
            return 0;
        }
        
        if(i==s.size() && j==p.size()){
            return 1;
        }
        
        if(i==s.size() && j<p.size()){
            while(j<p.size()){
                if(p[j] == '*'){
                    j++;
                }else if(j+1<p.size() && p[j+1]=='*'){
                    j=j+2;
                }else{
                    return 0;
                }
            }
            return 1;
        }
        
        
        if(dp[i][j] !=-1){
            return dp[i][j];
        }
        
        
        if(j+1<p.size() && p[j+1] == '*'){
            int x = func(s,p,i,j+2);
            if(s[i] == p[j] || p[j]=='.'){
               x = x || func(s,p,i+1,j);
            }
            dp[i][j] = x;
        }else{
            if(s[i] == p[j] || p[j] =='.'){
                dp[i][j] = func(s,p,i+1,j+1);
            }else{
                dp[i][j] = 0;
            }
        }

        return dp[i][j];
    }
    bool isMatch(string s, string p) {  
        dp = vector<vector<int>>(100,vector<int>(100,-1));
        if(func(s,p,0,0)==0){
            return false;
        }
        return true;
        
    }
};