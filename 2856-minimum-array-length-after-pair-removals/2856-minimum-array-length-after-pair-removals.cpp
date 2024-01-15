class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            um[nums[i]]++;
        }
        int maxFreq = 0;
        for(auto it = um.begin();it!=um.end();it++){
            maxFreq = max(maxFreq,it->second);
        }
        if(maxFreq<=n/2){
            return n%2;
        }
        return 2*maxFreq-n;
        
    }
};