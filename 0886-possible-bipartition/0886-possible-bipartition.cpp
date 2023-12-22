class Solution {
public:
    vector<vector<int>> adjList;
    vector<int> visit;
    bool bfs(int src){
        queue<int> q;
        q.push(src);
        visit[src] = 1;
        while(!q.empty()){
            int size = q.size();
            while(size){
                int p1 = q.front();
                q.pop();
                
                for(int i=0;i<adjList[p1].size();i++){
                    int p2 = adjList[p1][i];
                    if(visit[p2] == 0){
                        if(visit[p1] == 1){
                            visit[p2] = 2;
                        }else{
                            visit[p2] = 1;
                        }
                        q.push(p2);
                    }else{
                        if(visit[p1] == visit[p2]){
                            return false;
                        }
                    }
                    
                }
                size--;
            }
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        adjList = vector<vector<int>>(n);
        visit = vector<int>(n,0);
        for(vector<int> dislike : dislikes){
            adjList[dislike[0]-1].push_back(dislike[1]-1);
            adjList[dislike[1]-1].push_back(dislike[0]-1);
        }
        
        for(int i=0;i<n;i++){
            if(visit[i] == 0){
                if(bfs(i) == false){
                    return false;
                }
            }
        }
        return true;
        
    }
};