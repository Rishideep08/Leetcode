class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> um;
        int n = nums.size();
        for(int num: nums){
            um[num]++;
        }
        int max_freq = 0;
        for(auto it = um.begin();it!=um.end();it++){
            max_freq = max(max_freq,it->second);
        }
        unordered_map<int,pair<int,int>> maxFreqNums;
        for(int i=0;i<nums.size();i++){
            if(um[nums[i]] == max_freq){
                if(maxFreqNums.find(nums[i]) == maxFreqNums.end()){
                    maxFreqNums[nums[i]] = {i,i};
                }else{
                     maxFreqNums[nums[i]].second = i;
                }
            }
        }
        int ans = INT_MAX;
        for(auto it = maxFreqNums.begin();it!=maxFreqNums.end();it++){
            pair<int,int> temp = it->second;
            // cout<<it->first<<" "<<temp.first<<" "<<temp.second<<endl;
            ans = min(ans,temp.second - temp.first+1);
        }
        return ans;
    }
};