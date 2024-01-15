class Solution {
public:
    bool func(string pattern,string s,int i,int j,unordered_map<char,string>um,unordered_map<string,char>um1){
        if(i == pattern.size() && j==s.size()){
            return true;
        }
        
        if(i == pattern.size() || j==s.size()){
            return false;
        }
        if(um.find(pattern[i]) != um.end()){
            int size = um[pattern[i]].size();
            if(s.size()-j<size){
                return false;
            }
            string temp = s.substr(j,size);
            if(temp != um[pattern[i]]){
                return false;
            }
            return func(pattern,s,i+1,j+size,um,um1);
        }
        
        for(int i1 = j;i1<s.size();i1++){
            string temp = s.substr(j,i1-j+1);
            if(um1.find(temp) != um1.end()){
                continue;
            }
            um[pattern[i]] = temp;
            um1[temp] = pattern[i];
            if(func(pattern,s,i+1,i1+1,um,um1)==true){
                return true;
            }
            um1.erase(temp);
            um.erase(pattern[i]);
        }
        return false;
    }
    
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char,string>um;
        unordered_map<string,char>um1;
        return func(pattern,s,0,0,um,um1);
    }
};