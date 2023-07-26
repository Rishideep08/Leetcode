class Solution {
public:
    
    
    vector<vector<string>> res;
    
    bool isSafe(vector<string> &pattern,int r,int c){
        int n = pattern.size();
        for(int i=0;i<n;i++){
            if(pattern[i][c] == 'Q' ){
                return false;
            }
        }
        int r1 = r;
        int c1 = c;
        while(r1>=0 && c1>=0){
            if(pattern[r1][c1] =='Q'){
                return false;
            }
            r1--;
            c1--;
        }
        
        
        r1 = r;
        c1 = c;
        while(r1>=0 && c1<n){
            if(pattern[r1][c1] =='Q'){
                return false;
            }
            r1--;
            c1++;
        }
        
        return true;
    }
    
    
    void func(int index,vector<string> &pattern,int n){
        if(n==index){
            res.push_back(pattern);
            return;
        }
        
        for(int j=0;j<n;j++){
            if(isSafe(pattern,index,j)){
                pattern[index][j] = 'Q';
                func(index+1,pattern,n);
                pattern[index][j] = '.';
            }
        }
        
        return;
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        string str = "";
        for(int i=0;i<n;i++){
            str+='.';
        }
        // cout<<str<<endl;
        vector<string> pattern(n,str);
        // for(int i=0;i<n;i++){
        //     cout<<pattern[i]<<endl;
        // }
        func(0,pattern,n);
        return res;
    }
};