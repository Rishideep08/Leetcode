class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int minVal = *min_element(nums.begin(),nums.end());
        int maxVal = *max_element(nums.begin(),nums.end());
        vector<int> temp(maxVal-minVal+1,0);
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            temp[val-minVal]++;
        }
        int ans=0;
        int i = temp.size()-1;
        while(k>0){
            if(temp[i]>=k){
                return i+minVal;
            }else{
                k = k-temp[i];
                i--;
            }
        }
        return ans+minVal;
        
    }
};