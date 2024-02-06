class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0;
        int j=0;
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>> ans;
        while(i<n && j<m){
            if(firstList[i][1]<=secondList[j][1]){
                if(secondList[j][0]<=firstList[i][1]){
                    ans.push_back({max(firstList[i][0],secondList[j][0]),firstList[i][1]});
                }
                i++;
            }else{
                if(firstList[i][0]<=secondList[j][1]){
                    ans.push_back({max(firstList[i][0],secondList[j][0]),secondList[j][1]});
                }
                j++;
            }
        }
        return ans;
    }
};