class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(vector<int> flight:flights){
            adjList[flight[0]].push_back({flight[1],flight[2]});
        }
        
        queue<pair<int,int>> q;
        q.push({src,0});
        int level = 0;
        vector<int> costs(n,INT_MAX);
        costs[src]  = 0;
        while(!q.empty()){
            if(level>k){
                break;
            }
            
            int size = q.size();
            while(size){
                int u = q.front().first;
                int costu = q.front().second;
                q.pop();
                size--;
                if(u == dst){
                    continue;
                }
                
                for(int i=0;i<adjList[u].size();i++){
                    int v = adjList[u][i].first;
                    int price = adjList[u][i].second;
                    int priceV = costu+price;
                    if(priceV<costs[v]){
                        q.push({v,priceV});
                        costs[v] = priceV;
                    }
                }

            }
            // cout<<level<<endl;
            // for(int i=0;i<costs.size();i++){
            //     cout<<costs[i]<<" ";
            // }
            // cout<<endl;
            level++;
        }
        
        return costs[dst]==INT_MAX?-1:costs[dst];
    }
};