class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        if(n==0){
            return 0;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<vector<pair<int,int>>> adjList(n+1);
        
        for(int i=0;i<times.size();i++){
                adjList[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
    
        
        vector<int> dis(n+1,INT_MAX);
        dis[k] = 0;
        pq.push({0,k});
        
        while(!pq.empty()){
            pair<int,int> currNode = pq.top();
            pq.pop();
            int u = currNode.second;
            // cout<<u<<" "<<adjList[u].size()<<endl;
            for(int i=0;i<adjList[u].size();i++){
                int v = adjList[u][i].first;
                int w = adjList[u][i].second;
                if(dis[v]>dis[u]+w){
                    dis[v] = dis[u]+w;
                    pq.push({dis[v],v});
                }
            }
        }
        int maxVal = INT_MIN;
        for(int i=1;i<=n;i++){
            maxVal = max(maxVal,dis[i]);
        }
        
        return maxVal == INT_MAX?-1:maxVal;
    }
};