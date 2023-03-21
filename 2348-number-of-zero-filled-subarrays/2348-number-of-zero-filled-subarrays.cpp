class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans  = 0;
        int i=0;
        while(i<nums.size()){
            long long count = 0;
            while(i<nums.size() && nums[i] == 0){
                i++;
                count++;
            }
            ans = ans + (count*(count+1))/2;
            i++;
        }
        return ans;
    }
};