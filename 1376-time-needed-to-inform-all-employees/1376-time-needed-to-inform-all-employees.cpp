class Solution {
public:
    int doDfs(vector<vector<int>>&adjList,vector<int> &informTime,int root){
        
        if(adjList[root].size()==0){
            return 0;
        }
        
        
        int ans = informTime[root];
        int sum = 0;
        for(int i=0;i<adjList[root].size();i++){
           sum =  max(sum,doDfs(adjList,informTime,adjList[root][i]));
        }
        return ans+sum;
        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adjList(n);
        int root = 0;
        for(int i=0;i<manager.size();i++){
            if(manager[i] != -1){
                adjList[manager[i]].push_back(i);
            }else{
                root = i;
            }
        }
        
        
//         for(int i=0;i<n;i++){
//             cout<<i<<" : ";
//             for(int j=0;j<adjList[i].size();j++){
//                 cout<<adjList[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        return doDfs(adjList,informTime,root);
        
    }
};