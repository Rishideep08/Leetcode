class Solution {
public:
    bool doDfs(vector<vector<char>>& board, string word,int index,int i,int j){
        if(i<0 || i>=board.size() || j<0 || j>= board[0].size()||board[i][j]=='-1'){
            return false;
        }
        
        if(word[index] != board[i][j]){
            return false;
        }
        // cout<<i<<" "<<j<<" "<<index<<endl;x
        if(index == word.size()-1){
            return true;
        }
        char temp = board[i][j];
        
        board[i][j] = '-1';
        
        bool x = doDfs(board,word,index+1,i+1,j)||doDfs(board,word,index+1,i-1,j)
            ||doDfs(board,word,index+1,i,j+1)||doDfs(board,word,index+1,i,j-1); 
        
        board[i][j] = temp;
        
        return x;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
         int n = board.size();
         int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(doDfs(board,word,0,i,j) == true){
                    return true;
                }
            }
        }
        return false;
    }
};