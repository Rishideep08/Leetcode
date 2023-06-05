class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long int sum = 0;
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
            int rem = sum%k;
            if(rem == 0){
                if(i>=1)
                    return true;
            }
            if(um.find(rem) != um.end()){
                int j = um[rem];
                if(i-j>=2){
                    return true;
                }
            }else{
                um[rem] = i;
            }
        }
        return false;
        
    }
};