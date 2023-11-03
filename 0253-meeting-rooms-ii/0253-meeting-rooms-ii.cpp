class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans =0;
        for(int i=0;i<intervals.size();i++){
            while(!pq.empty() && pq.top()<=intervals[i][0]){
                pq.pop();
            }
            pq.push(intervals[i][1]);
            int val = pq.size();
            ans = max(ans,val);
        }
        
        return ans;
    }
};