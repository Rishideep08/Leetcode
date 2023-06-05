class Solution {
public:
    class compareIntervals{
        public:
        bool operator()(const vector<int> &interval1,const vector<int> &interval2){
            if(interval1[1]<interval2[1]){
                return true;
            }else if(interval1[1]==interval2[1]){
                return interval1[0]<interval2[0];
            }
            return false;
        }
    };
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compareIntervals());
        int n = intervals.size();
        multiset<int> starts;
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            auto itr = starts.lower_bound(intervals[i][1]);
            int val= distance(starts.begin(),itr);
            ans = max(ans,val+1);
            // cout<<val<<endl;
            
            
            starts.insert(intervals[i][0]);
        }
        
        return ans;
    }
};