class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> um,processed;
        for(int i=0;i<s.size();i++){
            um[s[i]]++;
        }
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(processed.find(s[i]) != processed.end()){
                um[s[i]]--;
                continue;
            }
            if(st.empty()){
                st.push(s[i]);
                processed[s[i]]++;
            }else{
                if(st.top() < s[i]){
                     st.push(s[i]);
                    processed[s[i]]++;
                }else{
                    while(!st.empty()){
                        if(um[st.top()]>0 && st.top()>=s[i]){
                            
                            processed[st.top()]--;
                            if(processed[st.top()]==0){
                                processed.erase(st.top());
                            }
                            st.pop();
                        }else{
                            break;
                        }
                    }
                    st.push(s[i]);
                    processed[s[i]]++;
                }
            }
            um[s[i]]--;
        }
        string res;
        while(!st.empty()){
            res = res + st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};