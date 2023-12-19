class Solution {
public:
    int helper(int x,int y, char ch){
        if(ch == '+'){
            return x+y;
        }
        return x-y;
    }
    int calculate(string str) {
        stack<pair<int,char>> s;
        int sum = 0;
        int curr = 0;
        char prevOper = '+';
        // s.push({0,'+'});
        for(int i=0;i<str.size();i++){
            if(str[i] == ' '){
                continue;
            }
            if(str[i] == '('){
                s.push({sum,prevOper});
                curr =0;
                sum = 0;
                prevOper = '+';
            }else{ 
                if(isdigit(str[i])){
                    curr = curr*10+(str[i]-'0');
                }else{
                    if(str[i] == '+'){
                        sum = helper(sum,curr,prevOper);
                        prevOper = '+';
                        curr = 0;
                    }else if(str[i] == '-'){
                        sum = helper(sum,curr,prevOper);
                        prevOper = '-';
                        curr = 0;
                    }else if(str[i] == ')'){
                        curr = helper(sum,curr, prevOper);
                        sum = s.top().first;
                        prevOper = s.top().second;
                        s.pop();
                        if(prevOper == '-' && curr <0){
                            curr = -curr;
                            prevOper = '+';
                        }
                        sum = helper(sum,curr,prevOper);
                        curr = 0;
                        prevOper = '+';
                    }
                }
            }
        }
        return helper(sum,curr,prevOper);
    }
};