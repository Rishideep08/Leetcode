class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int ans = 0;
        int maxValueCovered = 1;
        while(j<n){
            // int j = i;
            int coverage =0;
            while(j<n && j<maxValueCovered){
                coverage = max(coverage,j+1+nums[j]);
                j++;
            }  
            maxValueCovered = coverage;
            ans++;
        }
        
        return ans-1;
        
    }
};