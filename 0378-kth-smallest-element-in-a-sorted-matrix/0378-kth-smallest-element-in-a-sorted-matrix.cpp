class Solution {
public:
    int kthSmallest(vector<vector<int>>&matrix, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            pq.push({matrix[i][0],i,0});
        }
        int ans = 0;
        while(k){
            vector<int> temp = pq.top();
            pq.pop();
            ans = temp[0];
            int r = temp[1];
            int c = temp[2];
            if(c+1<n){
                pq.push({matrix[r][c+1],r,c+1});
            }
            k--;
        }
        
        
        
        return ans;
    }
};