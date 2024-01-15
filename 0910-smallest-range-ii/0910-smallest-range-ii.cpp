class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int minVal = nums[nums.size()-1]-nums[0];
        for(int i=0;i<nums.size()-1;i++){
            int possibleMax = max(nums[i]+k,nums[nums.size()-1]-k);
            int possibleMin = min(nums[0]+k,nums[i+1]-k);
            minVal = min(minVal,possibleMax-possibleMin);
        }
        return minVal;
    }
};