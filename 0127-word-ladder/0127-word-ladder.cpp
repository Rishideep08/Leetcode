class Solution {
public:
    vector<vector<int>> adjList;
    
    bool checkOneDiff(string a,string b){
        int count = 0;
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]){
                count++;
            }
        }
        if(count == 1){
            return true;
        }
        return false;
    }
    
    void createAdjList(vector<string>& wordList){
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(checkOneDiff(wordList[i],wordList[j])){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
    }
    
    int bfs(string beginWord, string endWord, vector<string>& wordList){
        queue<int> q;
        q.push(wordList.size()-1);
        vector<int> visit(wordList.size(),0);
        visit[wordList.size()-1] = 1;
        int level =1;
        while(!q.empty()){
            int size = q.size();
            while(size){
                int u = q.front();
                q.pop();
                
                if(wordList[u] == endWord){
                    return level;
                }
                for(int i=0;i<adjList[u].size();i++){
                    int v = adjList[u][i];
                    
                    if(visit[v] == 0){
                        q.push(v);
                        visit[v] = 1;
                    }
                }
                size--;
            }
            level++;
        }
        return 0;
    }
    
    int doBidirBfs(int beginIndex,int endIndex,vector<string>& wordList){
        
        if(beginIndex == endIndex){
            return 0;
        }
        
        queue<int> start,end;
        unordered_map<int,int>visitedStart,visitedEnd;
        
        
        
        start.push(beginIndex);
        end.push(endIndex);
        
        visitedStart.insert({beginIndex,0});
        visitedEnd.insert({endIndex,0});
        
        while(!start.empty() && !end.empty()){
            //forward pass.
            int startSize = start.size();
            // cout<<"forward:"<<endl;
            while(startSize){
                startSize--;
                int u = start.front();
                // cout<<wordList[u]<<" ";
                start.pop();
                
                for(int i=0;i<adjList[u].size();i++){
                    int v = adjList[u][i];
                    if(visitedStart.find(v) == visitedStart.end()){
                        visitedStart[v] = visitedStart[u]+1;
                        start.push(v);
                    }
                    
                    if(visitedEnd.find(v)!=visitedEnd.end()){
                        return visitedEnd[v]+visitedStart[v]+1;
                    }
                } 
            }
            // cout<<endl;
            
            //backward dir
            // cout<<"backward:"<<endl;
            int endSize = end.size();
            while(endSize){
                endSize--;
                int u = end.front();
                // cout<<wordList[u]<<" ";
                end.pop();
                
                for(int i=0;i<adjList[u].size();i++){
                    int v = adjList[u][i];
                    if(visitedEnd.find(v) == visitedEnd.end()){
                        visitedEnd[v] = visitedEnd[u]+1;
                        end.push(v);
                    }
                    
                    if(visitedStart.find(v)!=visitedStart.end()){
                        return visitedEnd[v]+visitedStart[v]+1;
                    }
                } 
            }
            // cout<<endl;
            
        }
        
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        
        wordList.push_back(beginWord);
        int n = wordList.size();
        adjList = vector<vector<int>>(n);
        createAdjList(wordList);
        
        // for(int i=0;i<adjList.size();i++){
        //     cout<<wordList[i]<<" : ";
        //     for(int j=0;j<adjList[i].size();j++){
        //         cout<<wordList[adjList[i][j]]<<" ";
        //     }
        //     cout<<endl;
        // }
        int endIndex = -1;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i] == endWord){
                endIndex = i;
                break;
            }
        }
        // hot : dot lot hit 
        // dot : hot dog lot 
        // dog : dot log cog 
        // lot : hot dot log 
        // log : dog lot cog 
        // cog : dog log 
        // hit : hot 
        if(endIndex == -1){
            return 0;
        }
        int startIndex = n-1;
        return doBidirBfs(startIndex,endIndex,wordList);
        
        // return 0;
    }
};