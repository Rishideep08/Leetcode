class Solution {
public:
    string convert(vector<vector<int>> &board){
        string res = "";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                res = res+to_string(board[i][j]);
            }
        }
        return res;
    }
    
    pair<int,int> getRC(vector<vector<int>>&board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
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
        
        queue<pair<vector<vector<int>>,string>> q;
        q.push({board,""});
        unordered_set<string> us;
        us.insert(convert(board));
        
        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};
        char dz[] = {'U','L','R','D'};
        
        int level = 0;
        string target = "123450";
        while(!q.empty()){
            int size = q.size();
            while(size){
                vector<vector<int>> temp = q.front().first;
                string str = q.front().second;
                q.pop();
                
                if(convert(temp) == target){
                    return level;
                }
                
                pair<int,int> rc = getRC(temp);
                
                int r = rc.first;
                int c = rc.second;
                
                for(int i=0;i<4;i++){
                    int r1 = r+dx[i];
                    int c1 = c+dy[i];
                    
                    if(r1>=0 && r1<n && c1>=0 && c1<m){
                        swap(temp[r][c],temp[r1][c1]);
                        if(us.find(convert(temp)) == us.end()){
                            us.insert(convert(temp));
                            q.push({temp,str+dz[i]});
                        }
                        swap(temp[r][c],temp[r1][c1]);
                    }
                }
                size--;
            }
            level++;
        }
        
        return -1;
    }
};