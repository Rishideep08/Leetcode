class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        for(int i=0;i<n;i++){
            pq.push({matrix[i][0],i,0});
        }
        
        while(k){
            vector<int> temp = pq.top();
            pq.pop();
            k--;
            if(k==0){
                return temp[0];
            }
            if(temp[2]+1<n){
                pq.push({matrix[temp[1]][temp[2]+1],temp[1],temp[2]+1});
            }

        }
        return -1;
        
        
    }
};