class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int start = 0;
        int end =0;
        int ans =0;
        int possibleEnds= 0;
        int count = 0;
        int n= nums.size();
        while(end<n){
            if(nums[end]%2 == 1){
                count++;
            }
            if(count == k){
                // cout<<"Hi "<<start<<" "<<end<<endl;
                possibleEnds++;
                ans++;
            }else if(count > k){
                // cout<<"addfdf"<<endl;
                if(nums[start]%2 == 1){
                        count--;
                }
                start++;
                while(count>k){
                    ans = ans+possibleEnds;
                    if(nums[start]%2 == 1){
                        count--;
                    }
                    start++;
                } 
                possibleEnds = 1;
                ans++;
            }
            end++;
        }
        
        if(nums[start]%2 == 1){
                count--;
        }
        start++;
        while(start<n && count==k){
            ans = ans+possibleEnds;
            if(nums[start]%2 == 1){
                count--;
            }
            start++;
        } 
        return ans;
    }
};