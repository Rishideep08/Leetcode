class Solution {
public:
    int doBFS(vector<vector<int>>& grid,int i,int j){
        int n = grid.size();
        if(n==0){
            return 0;
        }
        int m = grid[0].size();
        grid[i][j]= -1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int count = 0;
        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};
        while(!q.empty()){
            int size = q.size();
            while(size){
                pair<int,int> temp = q.front();
                q.pop();
                grid[i][j] = -2;
                count++;

                for(int i=0;i<4;i++){
                    int x1 = temp.first+dx[i];
                    int y1 = temp.second+dy[i];
                    
                    if(x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1] == 1){
                        grid[x1][y1] = -1;
                        q.push({x1,y1});
                    }
                }
                
                size--;
            }
        }
        return count;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0){
            return 0;
        }
        int m = grid[0].size();
        int maxVal = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    maxVal = max(maxVal,doBFS(grid,i,j));
                }
            }
        }
        return maxVal;
    }
};