class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<=2){
            return false;
        }
        vector<int> left(nums.size(),0),right(nums.size(),0);
        left[0] = nums[0];
        int n = nums.size();
        right[n-1] = nums[n-1];
        for(int i=1;i<nums.size();i++){
            left[i] = min(nums[i],left[i-1]);
        }
        
        for(int i=n-2;i>=0;i--){
            right[i] = max(nums[i],right[i+1]);
        }

        
        for(int i=1;i<n-1;i++){
            if(left[i-1] < nums[i] && nums[i]<right[i+1]){
                return true;
            }
        }
        
        return false;
        
    
    }
};