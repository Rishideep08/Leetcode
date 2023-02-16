class Solution {
public:
    int count;
    
    void func(int index,vector<int>&nums,int sum,int target){
        if(index == nums.size()){
            if(sum == target){
                count++;
            }
            return;
        }
        
        func(index+1,nums,sum+nums[index],target);
        func(index+1,nums,sum-nums[index],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        func(0,nums,0,target);
        return count;
    }
};