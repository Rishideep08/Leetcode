class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_map<int,int> um;
        int balance = 0;
        int start = 0;
        for(int i=0;i<s.size();i++){
          if(balance ==0 && s[i]==')'){
              um[i]++;
              continue;
          }
          if(s[i]=='('){
              balance++;
          }else if(s[i]==')'){
              balance--;
          }
        }
        balance = 0;
        for(int i=s.size()-1;i>=0;i--){
          if(balance ==0 && s[i]=='('){
              um[i]++;
              continue;
          }
          if(s[i]==')'){
              balance++;
          }else if(s[i]=='('){
              balance--;
          }
        }
        
        
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(um.find(i) == um.end()){
                ans+=s[i];
            }
        }
        
        return ans;
    }
};