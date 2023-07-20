class Solution {
public:
    
    
    bool check(vector<vector<int>>&board){
        int count = 1;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                // cout<<board[i][j]<<" abc ";
                if(i==board.size()-1 && j==board[i].size()-1){
                    continue;
                }
                if(board[i][j]!=count){
                    return false;
                }
                count++;
            }
            // cout<<endl;
            
        }
        // cout<<"-----\n";
        return true;
    }
    
    bool checkPossible(int i,int j,int n,int m){
        if(i<0 || i>=n ||j<0||j>=m){
            return false;
        }
        return true;
    }
    string convertVectortoString(vector<vector<int>> &board){
        string res = "";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                // cout<<board[i][j]<<" ";
                res = res + to_string(board[i][j]);
            }
            // cout<<endl;
        }
        // cout<<"----\n";
        return res;
    }

    unordered_set<string> us;
    
    int doBfs(vector<vector<int>>& board,int n,int m){

        
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        queue<vector<vector<int>>> q;
        q.push(board);
        string x1 = convertVectortoString(board);
        us.insert(x1);
        int val = INT_MAX;
        int level=0;
        while(!q.empty()){
            int n1 = q.size();
            while(n1){
                vector<vector<int>> temp = q.front();
                q.pop();
                
                // for(int i=0;i<temp.size();i++){
                //     for(int j=0;j<temp[i].size();j++){
                //         cout<<temp[i][j]<<" ";
                //     }
                //     cout<<endl;
                // }
                // cout<<"------\n";
                
                if(check(temp)){
                    return level;
                }
                
                int r = 0;
                int c = 0;
                for(int i=0;i<temp.size();i++){
                    for(int j=0;j<temp[i].size();j++){
                        if(temp[i][j] == 0){
                            r = i;
                            c = j;
                            break;
                        }
                    }
                }
                
                for(int i=0;i<4;i++){
                    int r1 = r+dx[i];
                    int c1 = c+dy[i];

                    if(checkPossible(r1,c1,n,m)){
                        swap(temp[r][c],temp[r1][c1]);
                        string x = convertVectortoString(temp);
                        if(us.find(x) == us.end()){
                            q.push(temp);
                            us.insert(x);
                        }
                        swap(temp[r][c],temp[r1][c1]);
                    }
                } 
                n1--;
            }
            
            level++;
        }
        return -1;
        
        
    }
    
    
    
    int slidingPuzzle(vector<vector<int>>& board) {
        int n= board.size();
        int m= board[0].size();
        return doBfs(board,n,m);
        
    }
};