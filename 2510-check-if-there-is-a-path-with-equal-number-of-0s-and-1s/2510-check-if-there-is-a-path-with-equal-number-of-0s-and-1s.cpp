class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    bool doDfs(vector<vector<int>>& grid,int i,int j,int n,int m, int val){
        if(i<0 || i>=n || j<0 || j>=m || val<0){
            return false;
        }
        if(dp[i][j][val] != -1){
            if(dp[i][j][val] == 1){
                return true;
            }
             return false;
        }
        int prev_val = val;
        if(grid[i][j] == 1){
            val--;
        }
        

        
        if(i==n-1 && j==m-1){
            if(val == 0){
                dp[i][j][prev_val] = 1;
                return true;
            }
            if(val>0)
                dp[i][j][prev_val] = 0;
            return false;
        }
        
        bool x = doDfs(grid,i+1,j,n,m,val);
        bool y = doDfs(grid,i,j+1,n,m,val);
        bool z = x||y;
        if(z == true){
            dp[i][j][prev_val] = 1;
        }else{
            dp[i][j][prev_val] = 0;
        } 
        
        
        return x||y;
    }
    
    
    bool isThereAPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        dp = vector<vector<vector<int>>> (101,vector<vector<int>>(101,vector<int>(101,-1)));
        
        int val = n+m-1;
        if(val%2 !=0){
            return false;
        }
        val = val/2;
        return doDfs(grid,0,0,n,m,val);
    }
};