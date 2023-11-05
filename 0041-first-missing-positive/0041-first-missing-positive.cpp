class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        for(int i=0;i<j;i++){
            int index = abs(nums[i])-1;
            if(index<j){
                if(nums[index]>0){
                    nums[index] = -nums[index];
                }
            }
        }
        for(int i=0;i<j;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return j+1;
    }
};