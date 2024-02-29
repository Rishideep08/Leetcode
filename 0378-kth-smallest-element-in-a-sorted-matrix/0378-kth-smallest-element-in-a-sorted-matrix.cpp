class Solution {
public:
    //from left-bottom or right-top, count how many numbers are less equal than mid
    int solve(vector<vector<int>>& matrix, int mid){
        int count = 0, n = matrix.size(), i = 0, j = n-1;
        while(i < n && j >= 0){
            if(matrix[i][j] > mid) j--;
            else{
                count += (j+1);
                i++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), i = matrix[0][0], j = matrix[n-1][n-1];
        while(i < j){
            int mid = i + (j-i)/2;
            int posi = solve(matrix, mid);
            if(posi < k) i = mid+1;
            else j = mid;
        }
        return i;
    }  
};