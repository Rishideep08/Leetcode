class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n= mat.size();
        int m = mat[0].size();
        int maxVal = (n-1+m-1);
        vector<int> ans;
        for(int k=0;k<=maxVal;k++){
            if(k%2 == 1){
                for(int i=0;i<=maxVal;i++){
                    int j = k-i;
                    if(i>=0 && i<n && j>=0 && j<m){
                        ans.push_back(mat[i][j]);
                    }
                }
            }else{
                for(int i=0;i<=maxVal;i++){
                    int j = k-i;
                    if(i>=0 && i<m && j>=0 && j<n){
                        ans.push_back(mat[j][i]);
                    }
                }
            }
        }
        return ans;
    }
};