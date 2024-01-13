class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> um, um1;
        for(int i=0;i<p.size();i++){
            um[p[i]]++;
        }
        int total = p.size();
        int start = 0;
        int end = 0;
        int n = s.size();
        int total1 = 0;
        vector<int> res;
        while(end<n){
            if(um.find(s[end]) == um.end()){
                start = end+1;
                um1.clear();
                total1= 0;
            }else{
                um1[s[end]]++;
                total1++;
                while(um1[s[end]] > um[s[end]]){
                    um1[s[start]]--;
                    total1--;
                    if(um1[s[start]] == 0){
                        um1.erase(s[start]);
                    }
                    start++;
                }
                if(um1[s[end]] == um[s[end]]){
                    if(total1 == total){
                        res.push_back(start);
                    }
                }
            }
            end++;
        }
        return res;
    }
};