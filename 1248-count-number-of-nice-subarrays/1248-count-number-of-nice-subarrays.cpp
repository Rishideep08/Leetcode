class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int n = nums.size();
        int ans = 0;
        int substrWithEnd = 0;
        int count = 0;

        while(end<n){
           if((nums[end]%2) != 0){
               count++;
           }
           int possibleStarts = 0;
           while(count==k){
                if(nums[start]%2!=0){
                    count--;
                }   
               start++;
               possibleStarts++;
           }
            if((nums[end]%2)!=0){
                substrWithEnd = possibleStarts;
            }
            ans = ans+substrWithEnd;
            end++;
        }
        
        return ans;
    }
};