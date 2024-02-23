class Solution {
public:
    string removeDuplicates(string s) {
        // stack<int> st;
        string res;
        for(int i=0;i<s.size();i++){
            if(res.size()==0||res[res.size()-1]!= s[i]){
                res.push_back(s[i]);
            }else{
                res.pop_back();
            }
        }
        return res;
    }
};