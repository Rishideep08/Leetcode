class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int end=0;
        int n = s.size();
        int maxLen = 0;
        unordered_map<char,int> um;
        while(end<n){
            if(um.find(s[end]) != um.end()){
               start = max(start,um[s[end]]+1);
            }
            um[s[end]] = end;
            maxLen = max(maxLen,end-start+1);
            end++;
        }
        return maxLen;
    }
};