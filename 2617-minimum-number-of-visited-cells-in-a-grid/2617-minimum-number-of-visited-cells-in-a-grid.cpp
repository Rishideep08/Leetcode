class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> visit(n,vector<int>(m,0));
        vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
        vector<int> row(n,0);
        vector<int> col(m,0);
            
        q.push({0,0});
        visit[0][0] = 1;
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                pair<int,int> ref = q.front();
                q.pop();
                int x = ref.first;
                int y = ref.second;
                
                if(min(m-1,y+grid[x][y])>max(row[x],y)){
                    int count = max(row[x],y)+1;
                    while(count<=min(m-1,y+grid[x][y])){
                        if(visit[x][count]==0){
                            visit[x][count] = visit[x][y]+1;
                            parent[x][count] = {x,y};
                            q.push({x,count});
                        }
                        count++;
                    }
                    row[x] = min(m-1,y+grid[x][y]);
                 }
                
                if(min(n-1,x+grid[x][y])>max(x,col[y])){
                    int count = max(x,col[y])+1;
                    while(count<=min(n-1,x+grid[x][y])){
                        if(visit[count][y] == 0){
                            visit[count][y] = visit[x][y]+1;
                            parent[count][y] = {x,y};
                            q.push({count,y});
                        }
                        count++;
                    }
                    col[y] = min(n-1,x+grid[x][y]);
                }
                

            }
        }

        
        if(visit[n-1][m-1] == 0)
        return -1;
        
        return visit[n-1][m-1];
        
    }
};