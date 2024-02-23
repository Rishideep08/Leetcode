class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(st.empty() || s[st.top()]!=s[i]){
                st.push(i);
            }else{
                st.pop();
            }
        }
        string res="";
        while(!st.empty()){
            res += s[st.top()];
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};