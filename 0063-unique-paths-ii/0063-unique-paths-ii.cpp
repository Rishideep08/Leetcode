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
        dp[0][1] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    dp[i+1][j+1] = 0;
                }else{
                    dp[i+1][j+1] = dp[i][j+1]+dp[i+1][j];
                }
            }
        }
        
        return dp[n][m];
    }
};