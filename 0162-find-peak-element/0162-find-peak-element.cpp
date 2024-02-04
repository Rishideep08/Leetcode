class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            
            long long int x = LONG_MIN;
            long long int y = LONG_MIN;
            if(m!=0){
                x =nums[m-1]; 
            }
            if(m!=nums.size()-1){
                y = nums[m+1];
            }
            
            if(nums[m]>x && nums[m]>y){
                return m;
            }
            if(nums[m]>x && nums[m]<y){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return -1;
    }
};