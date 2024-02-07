class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return;
        }
        int lsb = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                lsb = i;
                break;
            }
        }
        // cout<<lsb<<endl;
        if(lsb == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        reverse(nums.begin()+lsb+1,nums.end());
        auto itr = upper_bound(nums.begin()+lsb+1,nums.end(),nums[lsb]);
        int temp = *itr;
        *itr = nums[lsb];
        nums[lsb] = temp;
        return;
    }
};