class Solution {
    
private:
    vector<vector<int>> adjList;
    string colors;
    unordered_map<int,vector<int>> visitedNodes;
    vector<int> visit;
    int ans=0;
    
public:
    
    vector<int> doDfs(int index){
        if(visit[index]==1){
            vector<int> tempRes(26,INT_MAX);
            return tempRes;
        }
        
        
        if(visitedNodes.find(index) == visitedNodes.end()){
            visit[index] = 1;
            vector<int> tempRes(26,0);
            for(int i=0;i<adjList[index].size();i++){
                int v = adjList[index][i];
                
                const vector<int> &x = doDfs(v);
                
                for(int j=0;j<26;j++){
                    tempRes[j] = max(tempRes[j],x[j]);
                }       
            }
            
            if(tempRes[colors[index]-'a'] != INT_MAX){
                tempRes[colors[index]-'a']++;
            }
            
            ans = max(ans,*max_element(tempRes.begin(),tempRes.end()));
            visitedNodes[index] = tempRes;
            visit[index] = 0;
        }
        
        return visitedNodes[index];
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        this->colors = colors;
        adjList = vector<vector<int>>(n);
        visit = vector<int>(n,0);
        
        for(auto edge: edges){
            adjList[edge[0]].push_back(edge[1]);
        }
        
        for(int i=0;i<n;i++){
            if(visitedNodes.find(i) == visitedNodes.end()){
                const vector<int> &tempRes = doDfs(i);
                if(*max_element(tempRes.begin(),tempRes.end()) == INT_MAX){
                    return -1;
                }
            }
        }
        
        
            
        return ans;
        
    }
};