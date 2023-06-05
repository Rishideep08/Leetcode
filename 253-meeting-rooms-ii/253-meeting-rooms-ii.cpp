class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0;
        int maxVal = 1e6+10;
        vector<int> referenceArray(maxVal,0);
        
        for(int i=0;i<intervals.size();i++){
            referenceArray[intervals[i][0]]+=1;
            referenceArray[intervals[i][1]]+=-1;
        }
        int sum = 0;
        for(int i=0;i<maxVal;i++){
            sum = sum+referenceArray[i];
            ans = max(ans,sum);
        }
        
        return ans;
        
    }
};