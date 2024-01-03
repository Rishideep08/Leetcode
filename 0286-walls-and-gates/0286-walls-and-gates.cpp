class Solution {
public:
    void doDfs(vector<vector<int>>& rooms,int i,int j,int n,int m,int depth,vector<vector<int>>& visit){
        if(i>=n || i<0 || j<0 || j>=m || rooms[i][j]==-1 || visit[i][j] == 1){
            return;
        }
        visit[i][j] = 1;
        rooms[i][j] = min(rooms[i][j],depth);
        doDfs(rooms,i+1,j,n,m,depth+1,visit);
        doDfs(rooms,i-1,j,n,m,depth+1,visit);
        doDfs(rooms,i,j+1,n,m,depth+1,visit);
        doDfs(rooms,i,j-1,n,m,depth+1,visit);
        visit[i][j] = 0;
    }
    
    void doBfs(vector<vector<int>>& rooms,int i,int j){
        int n = rooms.size();
        int m = rooms[0].size();
        
        
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        
        queue<pair<int,int>> q;
        // vector<vector<int>> visit = vector<vector<int>>(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rooms[i][j] == 0){
                   q.push({i,j});
                    // visit[i][j] = 1;
                }
            }
        }
        
        
        
        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};
        
        int level = 1;
        
        while(!q.empty()){
            int size = q.size();
            while(size){
                pair<int,int> temp = q.front();
                q.pop();
                
                int x = temp.first;
                int y = temp.second;

                for(int i=0;i<4;i++){
                    int x1 = x+dx[i];
                    int y1 = y+dy[i];
                    
                    if(x1>=0 && y1>=0 && x1<n && y1<m && rooms[x1][y1] == INT_MAX ){
                        rooms[x1][y1] = level;
                        q.push({x1,y1});
                    }
                }
                
                size--;
            }
            level++;
        }
        
        return;
    }
};