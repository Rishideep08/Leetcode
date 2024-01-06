class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int num : nums){
            um[num]++;
        }
        int maxFreq = -1;
        int maxVal = -1;
        for(auto itr = um.begin();itr!=um.end();itr++){
            if(maxFreq<itr->second){
                maxFreq = itr->second;
            }
        }
        
        
        int l = 0,r=nums.size()-1;
        int ans = r-l+1;
        unordered_map<int,int> left,right;
        for(int i=0;i<nums.size();i++){
            if(um[nums[i]]==maxFreq){
                if(left.find(nums[i]) == left.end()){
                    left[nums[i]] = i;
                }
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(um[nums[i]]==maxFreq){
                ans = min(ans,i-left[nums[i]]+1);
                um[nums[i]]--;
            }
        }
        
        return ans;
        
    }
};