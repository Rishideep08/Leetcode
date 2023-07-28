class TreeAncestor {
public:
    vector<vector<int>> parentsList;
    vector<vector<int>> adjList;
    void dfs(int u,int p,int m){
        parentsList[u][0] = p;
        
        for(int i=1;i<=m;i++){
            parentsList[u][i] = parentsList[parentsList[u][i-1]][i-1];
        }
        
        for(int i=0;i<adjList[u].size();i++){
            dfs(adjList[u][i],u,m);
        }
        
        
        
    }
    
    TreeAncestor(int n, vector<int>& parent) {
        int m = 31;
        parentsList = vector<vector<int>>(n+1,vector<int>(m+1,0));
        adjList = vector<vector<int>>(n+2);
        for(int i=0;i<parent.size();i++){
                adjList[parent[i]+1].push_back(i+1);
        }
        dfs(1,0,m);        
    }
    
    int getKthAncestor(int node, int k) {
        int i=31;
        node++;
        int ans = node;
        while(i>=0){
            int val = 1<<i;
            int x = k&val;
            if(x!=0){
                ans = parentsList[ans][i];
            }
            i--;
        }
        return ans-1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */