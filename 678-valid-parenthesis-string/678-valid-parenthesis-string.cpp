class Solution {
    private : 
    vector<vector<int>> dp;
public:
    int func(int count,int i,string s){
        if(count<0){
            return false;
        }
        if(i==s.size()){
            if(count ==0){
                return true;
            }
            return false;
        }
        if(dp[i][count] !=-1){
            return dp[i][count];
        }
        if(s[i] == '('){
            dp[i][count]= func(count+1,i+1,s);
            return dp[i][count];
        }else if(s[i]==')'){
            dp[i][count] =  func(count-1,i+1,s);
            return dp[i][count];
        }
        
        dp[i][count] = func(count,i+1,s)||func(count+1,i+1,s)||func(count-1,i+1,s);
        return dp[i][count];
    }
    
    bool checkValidString(string s) {
        dp = vector<vector<int>>(200,vector<int>(200,-1));
        return func(0,0,s)==1?true:false;
    }
};