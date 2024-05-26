class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        if(nums.size() <2){
            return 0;
        }
        int n = nums.size();
        int maxVal= *max_element(nums.begin(),nums.end());
        int minVal = *min_element(nums.begin(),nums.end());
        int minIndex  =0;
        int maxIndex = nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == minVal){
                minIndex = i;
                break;
            }
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] == maxVal){
                maxIndex = i;
                break;
            }
        }
        int ans = minIndex+ n - maxIndex-1;
        
        if(maxIndex<minIndex){
            ans--;
        }
    
        return ans;
    }
    
};