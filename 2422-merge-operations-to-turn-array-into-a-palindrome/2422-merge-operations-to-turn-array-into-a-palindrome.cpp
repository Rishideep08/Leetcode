class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int i=0;
        int j = nums.size()-1;
        // vector<long long int> nums(nums1.size(),0);
        // for(int i=0;i<nums1.size();i++){
        //     nums[i] = nums1[i];
        // }
        int count = 0;
        while(i<=j){
            if(nums[i] == nums[j]){
                i++;
                j--;
            }else if(nums[i]>nums[j]){
                nums[j]-=nums[i];
                nums[i]-=nums[i];
                nums[j-1] += nums[j];
                j--;
                count++;
            }else{
                nums[i]-=nums[j];
                nums[j]-=nums[j];
                nums[i+1] +=nums[i];
                i++;
                count++;
            }
        }
        return count;
    }
};