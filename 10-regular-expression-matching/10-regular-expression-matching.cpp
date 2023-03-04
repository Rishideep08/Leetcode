class Solution {
public:
    int dp[30][30];
    bool checkValid(string s, string p, int i,int j){
        if(i<s.size() && j<p.size()){
            if(p[j] == '.' || s[i] == p[j]){
                return true;
            }
        }
        return false;
    }
   
    bool func(string s, string p,int i,int j){
        if(i>=s.size() && j>=p.size()){
            return true;
        }
        if(i<s.size() && j>=p.size()){
            return false;
        }
        // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        if(dp[i][j] != -1){
            if(dp[i][j] == 1){
                return true;
            }
            return false;
        }
        char nextChar = 'A';
        if(j<p.size()-1){
            nextChar = p[j+1];
        }
        bool x;
        if(nextChar == '*'){
            x = func(s,p,i,j+2);
            if(x == true){
                dp[i][j] = 1;
                return true;
            }
            if(checkValid(s,p,i,j)){
                bool temp = func(s,p,i+1,j);
                dp[i][j] = (temp==true?1:0);
                return temp;
            }else{
                dp[i][j] = 0;
                return false;
            }
        }else{
            if(checkValid(s,p,i,j)){
                bool temp = func(s,p,i+1,j+1);
                dp[i][j] = (temp==true?1:0);
                return temp;
            }
            dp[i][j] = 0;
            return false;
        }
       dp[i][j] = 1;
       return true;    
    }
    
    
    bool isMatch(string s, string p) {
        for(int i=0;i<30;i++){
            for(int j=0;j<30;j++){
                dp[i][j] = -1;
            }
        }
       return func(s,p,0,0);
    }
};