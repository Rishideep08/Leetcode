class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        vector<int> rows(n,0);
        vector<int> cols(m,0);
        for(int i=0;i<n;i++){
            // um[i] = grid[i];
            for(int j=0;j<m;j++){
                vector<int> temp;
                temp.push_back(grid[i][j]);
                temp.push_back(i);
                temp.push_back(j);
                pq.push(temp);
            }
        }    
        
        while(!pq.empty()){
            vector<int> temp = pq.top();
            pq.pop();
            int r = temp[1];
            int c = temp[2];
            int r_val = rows[r];
            int c_val = cols[c];
            int prev = grid[r][c];
            grid[r][c] = max(r_val,c_val)+1;
            rows[r] = grid[r][c];
            cols[c] = grid[r][c];
        }
        
        return grid;
    }
};