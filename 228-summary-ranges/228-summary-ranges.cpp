class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        if(nums.size() == 0){
            return res;
        }
        
        int i =0;
        while(i<nums.size()){
            int start= i;
            i++;
            while(i<nums.size() && nums[i] == nums[i-1]+1){
                i++;
            }
            
            if(i==start+1){
                res.push_back(to_string(nums[start]));
            }else{
                res.push_back(to_string(nums[start])+"->"+to_string(nums[i-1]));
            }
        }
        
        return res;
    }
};