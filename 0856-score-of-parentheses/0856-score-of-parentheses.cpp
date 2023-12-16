class Solution {
public:
    int scoreOfParentheses(string str) {
        int n= str.size();
        stack<int> s;
        int curr = 0;
        for(int i=0;i<n;i++){
            if(str[i] == '('){
                s.push(curr);
                curr = 0;
            }else{
                if(curr == 0){
                    int x = 0;
                    if(!s.empty()){
                        x = s.top();
                        s.pop();
                    }
                    curr = x+1;
                }else{
                    int x = 0;
                    if(!s.empty()){
                        x = s.top();
                        s.pop();
                    }
                    curr = x+2*curr;
                }
            }
        }
        return curr;
        
    }
};