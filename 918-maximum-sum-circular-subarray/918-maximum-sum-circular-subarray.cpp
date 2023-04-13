class Solution {
public:
    
    pair<int,int> maxSumSubArray(vector<int> &nums,int actualSize){
        int maxVal = INT_MIN;
        int tempMaxVal = 0;
        int n = nums.size();
        // cout<<"-------"<<endl;
        int index = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            tempMaxVal = tempMaxVal+nums[i];
            
            if(tempMaxVal>maxVal){
                maxVal = tempMaxVal;
                index = i;
            }
            if(tempMaxVal<0){
                tempMaxVal = 0;
            }
            
        }
        return {maxVal,index};
    }
    
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> reverseMaxVals(n);
        reverseMaxVals[n-1] = nums[n-1];
        int sum = nums[n-1];
        for(int i=n-2;i>=0;i--){
            sum = sum+nums[i];
            reverseMaxVals[i] = max(reverseMaxVals[i+1],sum);
        }
        sum = 0;
        pair<int,int> x = maxSumSubArray(nums,n);
        int maxVal = x.first;
        for(int i=0;i<n-1;i++){
            int extra = reverseMaxVals[i+1];
            sum = sum+nums[i];
            maxVal =max(maxVal,sum+extra);
        }
        // pair<int,int> x = maxSumSubArray(nums,n);
        return maxVal;
        
        
    }
};