class Solution {
public:
    int doBinarySearch(vector<int>&nums,int target,int l,int r){
        if(l==r){
            return nums[l] == target?l:-1; 
        }
        if(l==r-1){
            if(nums[l] == target){
                return l;
            }
            if(nums[r] == target){
                return r;
            }
            return -1;
        }
        
        int m = l+(r-l)/2;
        
        if(nums[m] == target){
            return m;
        }
        
        if(nums[m]>target){
            return doBinarySearch(nums,target,l,m-1);
        }
        
        return doBinarySearch(nums,target,m+1,r);
        
        
        
    }
    
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        if(l>r){
            return -1;
        }
        
        return doBinarySearch(nums,target,l,r);
    }
};