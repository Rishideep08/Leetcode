class Solution {
public:
vector<vector<int>> adjList;
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        adjList = vector<vector<int>>(n);
        vector<int> res;
        vector<int> indegrees(n,0);
        for(int i=0;i<prerequisites.size();i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegrees[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<indegrees.size();i++){
            if(indegrees[i] == 0){
                q.push(i);
            }
        }
        

        

        while(!q.empty()){
            int x = q.front();
            q.pop();
            // cout<<x<<endl;
            res.push_back(x);
            
            for(int i=0;i<adjList[x].size();i++){
                // cout<<"Hi"<<endl;
                int v= adjList[x][i];
                indegrees[v]--;
                if(indegrees[v] == 0){
                    q.push(v);
                }
            }
        }
            
        for(int i=0;i<n;i++){
            if(indegrees[i] != 0){
              
                return vector<int>(0);
            }
            // cout<<endl;
        }
        return res;
    }
};