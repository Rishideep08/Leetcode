class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n  = nums.size();
        int start = 0;
        int end = 0;
        int possibleEnds =0;
        int ans=0;
        int count =0;
        while(end<n){
            if(nums[end]%2 == 1){
                count++;
            }
            if(count == k){
                possibleEnds++;
                ans++;
            }else if(count>k){
                while(count>k){
                    if(nums[start]%2==0){
                        ans= ans+possibleEnds;
                    }else{
                        count--;
                    }
                    start++;
                }
                cout<<end<<" "<<start<<" "<<ans<<endl;
                possibleEnds = 1;
                ans++;
            }
            end++;
        }
        if(nums[start]%2 == 1){
            return ans;
        }
        start++;
        while(start<n){
            ans = ans+possibleEnds;
            if(nums[start]%2 == 1){
                break;
            }
            start++;
        }
        return ans;
    }
};