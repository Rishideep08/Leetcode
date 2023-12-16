class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        q.push(vector<int>{0,0,k});
        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};
        unordered_map<string,int> um;
        string val = to_string(0)+":"+to_string(0)+":"+to_string(k);
        um[val] = 0;
        
        
        while(!q.empty()){
            vector<int> temp = q.front();
            string val = to_string(temp[0])+":"+to_string(temp[1])+":"+to_string(temp[2]);
            if(temp[0] == n-1 && temp[1] == m-1){
                return um[val];
            } 
            q.pop();
            
            for(int i=0;i<4;i++){
                int x1 = temp[0]+dx[i];
                int y1 = temp[1]+dy[i];
                int k1 = temp[2];
                if(x1>=0 && y1>=0 && x1<n && y1<m){
                    if(grid[x1][y1] == 1 && k1<=0){
                        continue;
                    }
                    if(grid[x1][y1] == 1){
                        k1--;
                    }
                    string val1 = to_string(x1)+":"+to_string(y1)+":"+to_string(k1);
                    if(um.find(val1) == um.end()){
                        um[val1] = um[val]+1;
                        q.push(vector<int>{x1,y1,k1});
                    }
                }
            }
            
        }
        return -1;
    }
};