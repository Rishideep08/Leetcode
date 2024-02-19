class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int start = 0;start<n;start++){
            int i = start;
            int j = 0;
            int comp = matrix[i][j];
            while(i<n && j<m){
                if(matrix[i][j]!=comp){
                    return false;
                }
                i++;
                j++;
            }
        }
        
        for(int start = 1;start<m;start++){
            int i = 0;
            int j = start;
            int comp = matrix[i][j];
            while(i<n && j<m){
                if(matrix[i][j]!=comp){
                    return false;
                }
                i++;
                j++;
            }
        }
        
        return true;
    }
};