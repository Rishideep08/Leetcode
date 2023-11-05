class Solution {
public:
    bool check(string word1,string word2){
        int count = 0;
        for(int i=0;i<word1.size();i++){
            if(word1[i] != word2[i]){
                count++;
            }
        }
        if(count == 1){
            return true;
        }
        return false;
        
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool aval = false;
        int index = wordList.size();
        for(int i=0;i<wordList.size();i++){
            if(wordList[i] == beginWord){
                aval = true;
                index = i;
                break;
            }
        }
        
        if(aval == false){
            wordList.push_back(beginWord);
        }
        
        int n = wordList.size();
        vector<vector<int>> adjList(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(wordList[i],wordList[j])){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        queue<int> q;
        q.push(index);
        unordered_map<int,int> us;
        us[index] = 1;
        while(!q.empty()){
            int u = q.front();
            if(wordList[u] == endWord){
                return us[u];
            }
            q.pop();
            for(int i=0;i<adjList[u].size();i++){
                int v = adjList[u][i];
                if(us.find(v) == us.end()){
                    q.push(v);
                    us[v] = us[u]+1;
                }
            }
        }
        
        return 0;
        
    }
};