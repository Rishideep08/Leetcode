class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto edge:edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        q.push(0);
        vector<int> visit(n,0);
        vector<int> parent(n,0);
        visit[0] = 1;
        parent[0] = -1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int i=0;i<adjList[u].size();i++){
                int v = adjList[u][i];
                if(visit[v] == 1 && v!= parent[u]){
                    return false;
                }else{
                    if(visit[v] == 0){
                        q.push(v);
                        visit[v] = 1;
                        parent[v] = u;
                    }
                }
                
            }
        }
        
        for(int i=0;i<n;i++){
            if(visit[i] == 0){
                return false;
            }
        }
        return true;
    }
};