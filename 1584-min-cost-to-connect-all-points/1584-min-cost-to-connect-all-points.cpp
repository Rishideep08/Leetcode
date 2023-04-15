class Solution {
private :
    vector<int> parent;
public:
    int findParent(int u){
        if(u==parent[u]){
            return u;
        }
        
        // decreases the depth.
        parent[u] = findParent(parent[u]);
        
        return parent[u];
    }
    
    void doUnion(int u,int v){
        int parent_u = findParent(u);
        int parent_v = findParent(v);
        
        if(parent_u != parent_v){
            parent[parent_u] = v;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int w = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                vector<int> edge = {w,i,j};
                edges.push_back(edge);
            }
        }
        
        sort(edges.begin(),edges.end());
        parent = vector<int>(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        
        int sum = 0;
        
        for(int i=0;i<edges.size();i++){
            
            int u = edges[i][1];
            int v = edges[i][2];
            int w = edges[i][0];
            
            int parent_u = findParent(u);
            int parent_v = findParent(v);
            
            if(parent_u != parent_v){
                // cout<<u<<" "<<v<<" "<<parent_u<<" "<<parent_v<<endl;
                sum = sum+w;
                doUnion(u,v);
            }
            
            // cout<<"-------- parent start"<<endl;
            // for(int i=0;i<parent.size();i++){
            //     cout<<parent[i]<<" ";
            // }
            // cout<<endl;
            // cout<<"--------parent end"<<endl;
            
            
            
            
        }
        
        return sum;
        
    }
};