class Solution {
public:
    int visibleMountains(vector<vector<int>>& startIndexes) {
        if(startIndexes.size()==0){
            return 0;
        }
        for(int i=0;i<startIndexes.size();i++){
            startIndexes[i][0] = startIndexes[i][0]-startIndexes[i][1]; 
        }
        sort(startIndexes.begin(),startIndexes.end());
        int ans = 1;
        int activeEnd_x = startIndexes[0][0]+2*startIndexes[0][1];
        int activeHeight = startIndexes[0][1];
        int activeStart_x =  startIndexes[0][0];
        int flag = 1;
        for(int i=1;i<startIndexes.size();i++){
            int nextEnd_x = startIndexes[i][0]+2*startIndexes[i][1];
            if(activeStart_x == startIndexes[i][0] && nextEnd_x>=activeEnd_x){
                if(flag == 1){
                    ans--;
                    flag = 0;
                }
            }
            if(nextEnd_x>activeEnd_x){
                flag = 1;
                ans++;
                activeEnd_x = startIndexes[i][0]+2*startIndexes[i][1];
                activeStart_x = startIndexes[i][0];
            }

        }
        
        return ans;
        
    }
};