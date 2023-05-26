class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        if(peaks.size()==0){
            return 0;
        }
        vector<vector<int>> startIndexes;
        for(int i=0;i<peaks.size();i++){
            vector<int> temp;
            temp.push_back(peaks[i][0]-peaks[i][1]);
            temp.push_back(peaks[i][1]);
            startIndexes.push_back(temp);
        }
        sort(startIndexes.begin(),startIndexes.end());
        // for(int i=0;i<startIndexes.size();i++){
        //     cout<<startIndexes[i][0]<<" "<<startIndexes[i][1]<<endl;
        // }
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