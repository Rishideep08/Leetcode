class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = height[0];
        int i = 0;
        int j = height.size()-1;
        int right_max = height[height.size()-1];
        int ans = 0;
        while(i<=j){
            right_max = max(height[j],right_max);
            left_max = max(height[i],left_max);
            if(left_max<right_max){
                ans = ans + left_max-height[i];
                i++;
            }else{
                ans = ans + right_max-height[j];
                j--;
            }
        }
        return ans;
    }
};