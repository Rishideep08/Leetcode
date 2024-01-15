class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adjList(n);
        vector<int> indegree(n);
        vector<int> startTimes(n,-1);
        for(vector<int> relation : relations){
            adjList[relation[0]-1].push_back(relation[1]-1);
            indegree[relation[1]-1]++;
            
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                startTimes[i] = 0;
            }
        }
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            while(size){
                int u = q.front();
                q.pop();
                count++;
                
                for(int i=0;i<adjList[u].size();i++){
                    int v=adjList[u][i];
                    indegree[v]--;
                    startTimes[v] = max(startTimes[v],startTimes[u]+time[u]);
                    if(indegree[v] == 0){
                        q.push(v);
                    }
                }
                size--;
            }
        }
        
        if(count!=n){
            return -1;
        }
        int ans =0;
        for(int i=0;i<startTimes.size();i++){
            ans = max(ans,startTimes[i]+time[i]);
        }
        return ans;
    }
};