class Solution {
public:
    int pathSum(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        vector<vector<int>> adjList(5);
        int ans = 0;
        for(int i=0;i<5;i++){
            int size = int(pow(2,i));
            vector<int> temp(size,-1);
            adjList[i] = temp;
        }
        
        for(int num : nums){
            adjList[(num/100)-1][((num/10)%10)-1] = num%10;
        }
        
        // for(int i=0;i<4;i++){
        //     for(int j=0;j<adjList[i].size();j++){
        //         cout<<adjList[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=0;i<4;i++){
           for(int j=0;j<adjList[i].size();j++){
               if(adjList[i][j] == -1){
                   continue;
               }
               int flag = 0;
               if(adjList[i+1][2*j] != -1){
                   adjList[i+1][2*j]+=adjList[i][j];
                   flag = 1;
               }
               if(adjList[i+1][2*j+1] != -1){
                   adjList[i+1][2*j+1]+=adjList[i][j];
                   flag = 1;
               }
               
               if(flag == 0){
                   ans = ans + adjList[i][j];
               }
           }
        }
    
        
        
        return ans;
    }
};