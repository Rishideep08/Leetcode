class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int maxVal = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxVal){
                while(nums[i]-maxVal>1){
                        if(maxVal>=n){
                            return count;
                        }
                        maxVal = maxVal*2+1;
                        count++;
                    }
                    maxVal = maxVal+nums[i];
            }else{
                 maxVal = maxVal+nums[i];
            }
           if(maxVal>=n){
               return count;
           }
        }
        
        while(n>maxVal){
            maxVal = maxVal*2+1;
            count++;
        }
        
        return count;
    }
};