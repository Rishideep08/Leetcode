class Solution {
public:
    // int count = 0;
    vector<vector<int>> dp;
    int helper(int index,int n,vector<int>&visit,int val){
        if(index == n){
            return 1;
        }
        if(dp[index][val] != -1){
            return dp[index][val];
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(visit[i] == 0){
                if((i+1)%(index+1)==0 || (index+1)%(i+1)==0){
                    int val1 = 1<<i;
                    val1 = val + val1 ;
                    visit[i] = 1;
                    count = count+helper(index+1,n,visit,val1);
                    visit[i] = 0;
                }
                
            }
        }
        dp[index][val] = count;
        return dp[index][val];
        
    }
    
    int countArrangement(int n) {
        vector<int> visit(n,0);
        int maxVal = 1e6;
        dp = vector<vector<int>>(n+1,vector<int>(maxVal,-1));
        helper(0,n,visit,0);
        return dp[0][0];
        // return count;
    }
};