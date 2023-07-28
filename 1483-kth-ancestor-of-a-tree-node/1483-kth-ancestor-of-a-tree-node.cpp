class TreeAncestor {
public:
    vector<vector<int>> parentsList;
    vector<vector<int>> adjList;
    void dfs(int u,int p,int m){
        // cout<<u<<" "<<p<<endl;
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
        
        // for(int i=0;i<adjList.size();i++){
        //     cout<<i<<" : ";
        //     for(int j=0;j<adjList[i].size();j++){
        //         cout<<adjList[i][j]<< " ";
        //     }
        //     cout<<endl;
        // }
        dfs(1,0,m);
        
        // cout<<parentsList[1][0]<<endl;
        // for(int i=0;i<parentsList.size();i++){
        //     cout<<i<<" : ";
        //     for(int j=0;j<parentsList[i].size();j++){
        //         cout<<parentsList[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"HI"<<endl;
        
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
                // cout<<ans<<endl;
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