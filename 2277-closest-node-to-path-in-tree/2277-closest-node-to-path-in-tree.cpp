class Solution {
private:
    vector<vector<int>> adjList;   
    vector<vector<int>> lookup;
    unordered_map<string,vector<int>> memo;
    int n;
public:
    void doBfs(int index){
        queue<int> q;
        q.push(index);
        vector<int>visit(n,0);
        visit[index] = 1;
        lookup[index][index] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int i=0;i<adjList[u].size();i++){
                int v = adjList[u][i];
                if(visit[v] == 0){
                    visit[v] = 1;
                    lookup[index][v] = lookup[index][u]+1;
                    q.push(v);
                }
            }
        }
    }
    void doDfshelper(int start,int end,vector<int> &tempRes,int parent,int actualStart){
        tempRes.push_back(start);
        if(start == end){
            string val = to_string(actualStart)+" "+to_string(end);
            memo[val] = tempRes;
            return ;
        }
    
        for(int i=0;i<adjList[start].size();i++){
            if(adjList[start][i]!=parent)
                doDfshelper(adjList[start][i],end,tempRes,start,actualStart);
        }
        tempRes.pop_back();
        
        
    }
    
    int doDFS(int start, int end, int node){
        vector<int> tempRes;
        string val = to_string(start)+" "+to_string(end);
        
        if(memo.find(val) == memo.end()){
            doDfshelper(start,end,tempRes,-1,start);
        }
        
        vector<int> res = memo[val];
        // cout<<res.size()<<endl;
        
        int minVal = INT_MAX;
        int ans = start;
        
        for(int i=0;i<res.size();i++){
            if(minVal>lookup[node][res[i]]){
                minVal = lookup[node][res[i]];
                ans = res[i];
            }
            minVal = min(minVal,lookup[node][res[i]]);
        }
        return ans;
    }
    
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        adjList = vector<vector<int>>(n);
        lookup = vector<vector<int>>(n,vector<int>(n,0));
        this-> n = n;
        
        
        for(int i=0;i<edges.size();i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<n;i++){
            doBfs(i);
        }
        
        vector<int> res;
        for(int i=0;i<query.size();i++){
            if(query[i][0]>query[i][1]){
                swap(query[i][0],query[i][1]);
            }
            // cout<<query[i][0]<<" "<<query[i][1]<<endl;
            res.push_back(doDFS(query[i][0],query[i][1],query[i][2]));
        }
        
        return res;
    }
};