class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,0),right(n,0);
        int min_val = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] > min_val){
                left[i] = 1;
            }
            min_val = min(min_val,nums[i]);
        }
        int max_val = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]<max_val){
                right[i] = 1;
            }
            
            max_val = max(max_val,nums[i]);
        }
        for(int i=1;i<n-1;i++){
            if(left[i] == 1 && right[i] == 1){
                return true;
            }
        }
        return false;
    }
};