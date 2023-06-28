class Solution {
public:
    vector<vector<int>> dp;
    int func(int n,int eggs){
        // cout<<n<<" "<<eggs<<endl;
        if(n == 0){
            return 0;
        }
        
        if(eggs == 1){
            return n;
        }
        
        if(dp[n][eggs] == -1){
            int val = INT_MAX;
            for(int i=1;i<=n;i++){
                val = min(val,max(func(i-1,eggs-1),func(n-i,eggs))+1);
            }
            dp[n][eggs] = val;
            
        }
        
        
        return  dp[n][eggs];
        
        
    }
    
    
    
    int twoEggDrop(int n) {
        dp = vector<vector<int>>(1002,vector<int>(3,-1));
        return func(n,2);
    }
};