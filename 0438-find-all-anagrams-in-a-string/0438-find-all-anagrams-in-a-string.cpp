class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> um,um1;
        vector<int> ans;
        
        if(p.size()>s.size()){
            return ans;
        }
        for(int i=0;i<p.size();i++){
            um[p[i]]++;
            um1[s[i]]++;
        }
        if(um == um1){
            ans.push_back(0);
        }
        
        for(int i=1;i<s.size()-p.size()+1;i++){
            um1[s[i-1]]--;
            if(um1[s[i-1]] == 0){
                um1.erase(s[i-1]);
            }
            um1[s[i+p.size()-1]]++;
            if(um1 == um){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};