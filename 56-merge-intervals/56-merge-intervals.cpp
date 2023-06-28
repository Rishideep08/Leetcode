class Solution {
public:
    
    static bool comp(vector<int> & a,vector<int>&b){
        if(a[0]<b[0]){
            return true;
        }
        if(a[0] == b[0]){
            return a[1]<b[1];
        }
        return false;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> res;
        for(int i=0;i<intervals.size();i++){
            vector<int> temp;
            temp = intervals[i];
            while(i+1<intervals.size() && temp[1]>=intervals[i+1][0]){
                temp[0] = min(temp[0],intervals[i+1][0]);
                temp[1] = max(temp[1],intervals[i+1][1]);
                i++;
            }
            res.push_back(temp);
        }
        
        return res;
    }
};