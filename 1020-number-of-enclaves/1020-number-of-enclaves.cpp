class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        int n = grid.size();
        int m= grid[0].size();
        
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1){
                q.push({i,0});
                grid[i][0] = 2;
            }
            if(grid[i][m-1] == 1){
                q.push({i,m-1});
                grid[i][m-1] = 2;
            }
            
        }
        
        for(int i=0;i<m;i++){
            if(grid[0][i] == 1){
                if(i!=0 && i!=m-1)
                    q.push({0,i});
                grid[0][i] = 2;
            }
            if(grid[n-1][i] == 1){
                if(i!=0 && i!=m-1){
                    q.push({n-1,i});
                }
                grid[n-1][i] = 2;
            }
        }
        
        while(!q.empty()){
            pair<int,int> temp = q.front();
            q.pop();
            
            int x = temp.first;
            int y = temp.second;
            
            
            for(int i=0;i<4;i++){
                int x_new = x+dx[i];
                int y_new = y+dy[i];
                
                if(x_new>=0 && x_new <n && y_new>=0 && y_new<m && grid[x_new][y_new] == 1){
                    grid[x_new][y_new] = 2;
                    q.push({x_new,y_new});
                }
            }
        }
        
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};