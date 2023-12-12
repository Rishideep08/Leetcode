class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int n= nums.size();
        long long int ans = 0;
        int maxVal = *max_element(nums.begin(),nums.end());
        while(end<n){
            if(nums[end]==maxVal){
                k--;
            }
            while(k == 0){
                ans = ans + n-end;
                if(nums[start] == maxVal){
                    k++;
                }
                start++;
            }
            end++;
        }
        return ans;
    }
};