class Solution {
public:
     int getPower(char op){
        if(op =='/'||op =='*'){
            return 3;
        }
        return 2;
    }
    int evaluate(int val1,int val2, char op){
        if(op == '/'){
            return val1/val2;
        }
        if(op == '*'){
            return val1*val2;
        }
        if(op == '+'){
            return val1+val2;
        }
        return val1-val2;
    }
    int calculate(string str) {
        stack<pair<int,char>> s;
        int curr = 0;
        for(int i=0;i<str.size();i++){
            if(str[i] == ' '){
                continue;
            }
            if(isdigit(str[i])){
                curr = curr*10 + (str[i]-'0');
            }else{
                int operatorPower = getPower(str[i]);
                while(!s.empty() && getPower(s.top().second)>= operatorPower){
                    curr = evaluate(s.top().first,curr,s.top().second);
                    s.pop();
                }
                s.push({curr,str[i]});
                curr = 0;
            }
        }
        int operatorPower = 0;
        while(!s.empty() && getPower(s.top().second)>= operatorPower){
            curr = evaluate(s.top().first,curr,s.top().second);
            s.pop();
        }
        return curr;
    }
};