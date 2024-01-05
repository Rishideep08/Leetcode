class Solution {
public:
    int scoreOfParentheses(string str) {
        int curr = 0;
        stack<pair<int,int>> s;
        for(int i=0;i<str.size();i++){
            if(str[i] == ')'){
                int startIndex = s.top().first;
                int prevCurr = s.top().second;
                s.pop();
                
                if(startIndex == i-1){
                    curr = 1;
                }else{
                    curr = 2*curr;
                }
                
                curr = curr + prevCurr;
            }else{
                s.push({i,curr});
                curr = 0;
            }
        }
        return curr;
    }
};