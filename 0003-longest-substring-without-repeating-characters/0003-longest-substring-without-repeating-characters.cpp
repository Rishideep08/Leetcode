class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int end=0;
        int n = s.size();
        int maxLen = 0;
        unordered_map<char,int> um;
        while(end<n){
            while(um.find(s[end]) != um.end()){
                um[s[start]]--;
                if(um[s[start]] == 0){
                    um.erase(s[start]);
                }
                start++;
            }
            um[s[end]]++;
            maxLen = max(maxLen,end-start+1);
            end++;
        }
        return maxLen;
    }
};