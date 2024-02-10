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
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        
        wordList.push_back(beginWord);
        int n = wordList.size();
        adjList = vector<vector<int>>(n);
        createAdjList(wordList);
        
        // for(int i=0;i<n;i++){
        //     cout<<wordList[i]<<" : ";
        //     for(int j=0;j<adjList[i].size();j++){
        //         cout<<wordList[adjList[i][j]]<<" ";
        //     }
        //     cout<<endl;
        // }
        
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
};