class Solution {
public:
    int getHeuristicEstimate(vector<vector<int>>& board){
        int n = board.size();
        int m = board[0].size();
        int count = 1;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1 && j==m-1)
                    continue;
                if(board[i][j]!=count){
                    ans++;
                }
                count++;
            }
        }
        
        return ans;
    }
    
    
    string convert(vector<vector<int>>& board){
        int n = board.size();
        int m = board[0].size();
        string res = "";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res = res + to_string(board[i][j]);
            }
        }
        return res;
    }
    
    pair<int,int> getIndexes(vector<vector<int>>& board){
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 0){
                    return {i,j};
                }
            }
        }
        return {0,0};
    }
    
    
    int slidingPuzzle(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        priority_queue<pair<int,pair<int,vector<vector<int>>>>,vector<pair<int,pair<int,vector<vector<int>>>>>,greater<pair<int,pair<int,vector<vector<int>>>>>> pq;
        
        pq.push({getHeuristicEstimate(board),{0,board}});
        
        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};
        int dz[] = {'U','L','R','D'};
        int ans = 0;
        unordered_set<string> us;
        while(!pq.empty()){
            vector<vector<int>> temp = pq.top().second.second;
            int level = pq.top().second.first;
            pq.pop();
            us.insert(convert(temp));
            // cout<<convert(temp)<<" "<<val<<" "<<ans<<endl;
            if(convert(temp) == "123450"){
                return level;
            }
            // ans++;
            pair<int,int> rc = getIndexes(temp);
            int r = rc.first;
            int c = rc.second;
            
            for(int i=0;i<4;i++){
                int r1= r+dx[i];
                int c1 = c+dy[i];
                
                if(r1>=0 && c1>=0 && r1<n && c1<m){
                    swap(temp[r][c],temp[r1][c1]);
                    if(us.find(convert(temp)) == us.end()){
                        int val1 = level+1+getHeuristicEstimate(temp);
                        pq.push({val1,{level+1,temp}});
                    }
                    swap(temp[r][c],temp[r1][c1]);
                }
            }
        }
        return -1;
        
    }
};