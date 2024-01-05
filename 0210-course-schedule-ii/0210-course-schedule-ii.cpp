class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        vector<vector<int>> adjList(numCourses);
        for(vector<int> prereq : prerequisites){
            adjList[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }
        queue<int> q;
        
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                int u = q.front();
                q.pop();
                count++;
                ans.push_back(u);
                
                for(int i=0;i<adjList[u].size();i++){
                    int v = adjList[u][i];
                    indegree[v]--;
                    if(indegree[v] == 0){
                        q.push(v);
                    }
                }
                size--;
            }
        }
        
        if(count != numCourses){
            vector<int> res;
            return res;
        }
        
        return ans;
        
    }
};