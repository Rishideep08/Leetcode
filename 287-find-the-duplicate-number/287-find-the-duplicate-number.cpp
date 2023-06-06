class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         int slow = nums[0];
//         int fast = nums[0];
        
//         while(slow!=fast){
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//         }
        
        for(int i=0;i<nums.size();i++){
            int val = abs(nums[i]);
            if(nums[val]<=0){
                return val;
            }
            nums[val] = -1*nums[val];
        }
        return 1;
        
    }
};