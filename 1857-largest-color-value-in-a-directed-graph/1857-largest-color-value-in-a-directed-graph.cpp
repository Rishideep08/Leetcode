
class Solution {
    private :
    vector<vector<int>> adjList;
    vector<int> visit;
    unordered_map<int,vector<int>> visitedNodes;
    string colors;
    int ans;
    
public:
    
    vector<int> doDfs(int index){
        
        // cout<<index<<endl;
        if(visit[index] == 1){
            // cout<<"----"<<endl;
            vector<int> tempRes(26,INT_MAX);
            return tempRes;
        }
        visit[index] = 1;
        
        if(visitedNodes.find(index) != visitedNodes.end()){
            visit[index] = 0;
            return visitedNodes[index];
        }
        
        vector<int> tempRes(26,0);
        
        
        
        for(int i=0;i<adjList[index].size();i++){
            int v = adjList[index][i];
            // cout<<v<<endl;
            const vector<int> &x = doDfs(v);
            // cout<<index<<" "<<v<<endl;
            for(int j=0;j<26;j++){
                tempRes[j] = max(tempRes[j],x[j]);
                // if(x[j]!=0)
                // cout<<j<<" : "<<x[j]<<endl;
            }
            // cout<<" ----"<<endl;
            
        }
        
        if(tempRes[colors[index]-'a'] != INT_MAX){
            tempRes[colors[index]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            ans = max(ans,tempRes[i]);
        }
        
        visitedNodes[index] = tempRes;
        visit[index]= 0;
        
        
        // cout<<index<<" ended "<<endl;
        return tempRes;
        
        
    }
    
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n  = colors.size();
        this->colors = colors;
        adjList = vector<vector<int>>(n);
        visit = vector<int>(n,0);
        
        
        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
        }
        
        
        for(int i=0;i<n;i++){
            if(visitedNodes.find(i) == visitedNodes.end()){
                const vector<int> &res = doDfs(i);
                
                if(*max_element(res.begin(),res.end()) == INT_MAX){
                    return -1;
                }
            }
        }
        
        
        
        
        return ans;
        
    }
};