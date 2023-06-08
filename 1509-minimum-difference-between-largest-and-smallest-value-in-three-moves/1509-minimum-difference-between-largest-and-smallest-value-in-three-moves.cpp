class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=3)
            return 0;
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[n-4]-nums[0];
        ans = min(ans,nums[n-3]-nums[1]);
        ans = min(ans,nums[n-2]-nums[2]);
        ans = min(ans,nums[n-1]-nums[3]);
        
        return ans;
        
        
    }
};