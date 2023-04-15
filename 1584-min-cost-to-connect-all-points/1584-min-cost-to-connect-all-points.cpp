class Solution {
private : 
    
    class Edge{
        public:
            Edge(int v,int w) : v(v),w(w){}
        
            int v;
            int w;

    };
    
    vector<vector<Edge>> adjList;
    
public:
    
    class MSTNode{        
        public:
           int key;
            int value;
            MSTNode(int key,int value):key(key),value(value){
                
            }
    };
    
    class Compare{
        public:
            bool operator()(MSTNode m1, MSTNode m2){
                if(m1.value >= m2.value){
                    return true;
                }
                return false;
            }
    };
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
//         prim's solution
        int n = points.size();
        adjList = vector<vector<Edge>>(n);
        priority_queue<MSTNode,vector<MSTNode>,Compare> MstTree;
        unordered_set<int> foundSet;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int w=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adjList[i].push_back(Edge(j,w));
                adjList[j].push_back(Edge(i,w));
            }
            if(i==0){
                MstTree.push(MSTNode(i,0));
            }else{
                MstTree.push(MSTNode(i,INT_MAX));
            }
        }
        
        long long sum = 0;

        while(foundSet.size() != n){
            MSTNode newVertex = MstTree.top();
            MstTree.pop();
            int u = newVertex.key;
            if(foundSet.find(u) == foundSet.end()){
                sum = sum + newVertex.value;
                foundSet.insert(u);
            }else{
                continue;
            }
            
            for(int i=0;i<adjList[u].size();i++){
                int v = adjList[u][i].v;
                int w = adjList[u][i].w;
                
                if(foundSet.find(v) == foundSet.end()){
                    MstTree.push(MSTNode(v,w));
                }
                
            }
        }
        
        return sum;
        
        
        
        
        
        
        
    }
};