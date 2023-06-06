class Solution {
public:
    int minAddToMakeValid(string str) {
        stack<int> s;
        for(int i=0;i<str.size();i++){
            if(str[i] == ')'){
                if(!s.empty() && str[s.top()] == '('){
                    s.pop();    
                }else{
                    s.push(i);
                }
            }else{
                s.push(i);
            }
        }
        return s.size();
    }
};