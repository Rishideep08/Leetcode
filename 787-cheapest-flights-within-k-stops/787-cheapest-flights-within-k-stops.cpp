class Solution {
    private:
        vector<vector<pair<int,int>>> adjList;
public:
    
    int doBFSKdim(int src,int dst,int k,int n){
        queue<vector<int>> q;
        vector<int> start;
        start.push_back(src);
        start.push_back(0);
        start.push_back(0);
        q.push(start);
        // int minVal = INT_MAX;
        vector<int> distance(n,INT_MAX);
        distance[src]= 0;
        while(!q.empty()){
            vector<int> nodeDimPrice = q.front();
            q.pop();
            if(nodeDimPrice[1] == k+1){
                continue;
            }
            
            for(int i=0;i<adjList[nodeDimPrice[0]].size();i++){
                if(nodeDimPrice[2]+adjList[nodeDimPrice[0]][i].second < distance[adjList[nodeDimPrice[0]][i].first]){
                    distance[adjList[nodeDimPrice[0]][i].first] = nodeDimPrice[2]+adjList[nodeDimPrice[0]][i].second;
                    vector<int> futureNode;
                    futureNode.push_back(adjList[nodeDimPrice[0]][i].first);
                    futureNode.push_back(nodeDimPrice[1]+1);
                    futureNode.push_back(nodeDimPrice[2]+adjList[nodeDimPrice[0]][i].second);
                    q.push(futureNode);
                }
            }
        }
        
        return distance[dst]==INT_MAX ?-1:distance[dst];
    }
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        adjList = vector<vector<pair<int,int>>>(n);
        for(int i=0;i<flights.size();i++){
            adjList[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        return doBFSKdim(src,dst,k,n);
        
    }
};