class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(um.find(target-nums[i])!=um.end()){
                if(i!=um[target-nums[i]]){
                res.push_back(i);
                res.push_back(um[target-nums[i]]);
                return res;
            }
            }
            um[nums[i]] = i;
        }
        return res;
    }
};