class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int,int> um;
        for(int i=0;i<time.size();i++){
            int b = time[i]%60;
            ans = ans + um[(60-b)%60];
            um[b]++;
        }
        return ans;
    }
};