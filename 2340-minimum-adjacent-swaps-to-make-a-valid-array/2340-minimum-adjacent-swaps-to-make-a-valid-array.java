class Solution {
    public int minimumSwaps(int[] nums) {
        if(nums.length <2){
            return 0;
        }
        int maxVal = nums[0];
        int minVal = nums[0];
        int maxIndex = 0;
        int minIndex = 0;
        for(int i=1;i<nums.length;i++){
            if(maxVal<=nums[i]){
                maxIndex = i;
                maxVal = nums[i];
            }
        }
        
        for(int i=1;i<nums.length;i++){
            if(minVal>nums[i]){
                minIndex = i;
                minVal = nums[i];
            }
        }
        // cout<<maxIndex<<" "<<minIndex<<endl;
        System.out.println(maxIndex+" "+minIndex);
        
        
        int ans = nums.length - maxIndex-1;
        
        ans = ans + minIndex;
        if(maxIndex<minIndex){
            ans--;
        }
        
        return ans;
    }
}