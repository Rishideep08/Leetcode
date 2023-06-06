class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        long long int sum = 0;
        int count = 0;
        um[0] = 1;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
            int extra = sum-k;
            count = count + um[extra];
            um[sum]++;
        }
        return count;
        
    }
};