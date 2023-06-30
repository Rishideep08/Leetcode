class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        long long ans = 0;
        long long temp = 0;
        unordered_set<int> distinctSet;
        while(end<nums.size()){
            if(distinctSet.find(nums[end]) != distinctSet.end()){
                temp = temp- nums[start];
                distinctSet.erase(nums[start]);
                start++;
            }else{
                temp = temp+nums[end];
                distinctSet.insert(nums[end]);
                end++;
            }
            
            if(distinctSet.size() == k){
                ans = max(ans,temp);
                temp = temp-nums[start];
                distinctSet.erase(nums[start]);
                start++;
            }
        }
        
        return ans;
    }
};