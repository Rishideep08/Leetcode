class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        
        if(n==0){
            return 0;
        }
        if(grid[0][0] == 1){
            return 0;
        }
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1 && j==1){
                    dp[i][j] = 1;
                    continue;
                }
                if(grid[i-1][j-1] == 1){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        
        return dp[n][m];
    }
};