class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string token : tokens){
            if(token == "+" || token == "-" ||token == "*"||token == "/"){
                if(s.empty()){
                    return -1;
                }
                int x = s.top();
                s.pop();
                if(s.empty()){
                    return -1;
                }
                int y = s.top();
                s.pop();
                // swap(x,y);
                if(token=="+"){
                    s.push(x+y);
                }else if(token == "-"){
                     s.push(y-x);
                }else if(token == "*"){
                     s.push(x*y);
                }else if(token == "/"){
                     s.push(y/x);
                }
            }else{
                s.push(stoi(token));
            }
        }
        
        if(s.size() == 0||s.size()>1){
            return -1;
        }
        return s.top();
    }
};