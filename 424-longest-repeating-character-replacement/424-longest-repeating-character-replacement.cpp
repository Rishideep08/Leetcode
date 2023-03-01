class Solution {
public:
    int longestSubStr(string s,int k, char ch){
        int start = 0;
        int end = 0;
        int count =0;
        int n = s.size();
        unordered_map<char,int> um;
        while(end<n){
            um[s[end]]++;
            int needToChange = end-start+1-um[ch];
            while(needToChange >k ){
                um[s[start]]--;
                if(um[start] ==0 ){
                    um.erase(start);
                }
                start++;
                needToChange = end-start+1-um[ch];
            }
            count = max(count,end-start+1);
            end++;
        }
        // cout<<count<<endl;
        return count;
    }
    int characterReplacement(string s, int k) {
        int maxVal = 0;
        for(int i=0;i<26;i++){
            maxVal = max(maxVal,longestSubStr(s,k,'A'+i));
        }
        return maxVal;
    }
};