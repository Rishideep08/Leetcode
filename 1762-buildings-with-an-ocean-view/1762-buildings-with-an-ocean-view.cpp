class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int maxHeight = -1;
        vector<int> ans;
        for(int i=heights.size()-1;i>=0;i--){
            if(heights[i]>maxHeight){
                maxHeight = heights[i];
                ans.push_back(i);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};