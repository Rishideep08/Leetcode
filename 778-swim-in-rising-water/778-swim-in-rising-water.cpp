class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));

        pq.push({grid[0][0],{0,0}});
        dis[0][0] = grid[0][0];
        
        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};
        
        
        while(!pq.empty()){
            pair<int,pair<int,int>> temp = pq.top();
            pair<int,int> node = temp.second;
            pq.pop();
            
            if(node.first == n-1 && node.second == m-1){
                return temp.first;
            }
            
            for(int i=0;i<4;i++){
                int nb_x = node.first+dx[i];
                int nb_y = node.second+dy[i];
                if(nb_x<0 || nb_x>=n || nb_y<0 || nb_y>=m){
                    continue;
                }
                int extraWeight = grid[nb_x][nb_y]-temp.first;
                if(extraWeight<0){
                    extraWeight = 0;
                }
                if(dis[nb_x][nb_y]>dis[node.first][node.second]+extraWeight){
                    dis[nb_x][nb_y] = dis[node.first][node.second]+extraWeight;
                    pq.push({dis[nb_x][nb_y],{nb_x,nb_y}});
                }
                
            }    
        }
        
         return -1;
    }
};