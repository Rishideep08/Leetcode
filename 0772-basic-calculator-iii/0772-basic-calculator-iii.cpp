class Solution {
public:
    int eval(int x,int y, char op){
        if(op == '+'){
            return x+y;
        }
        if(op == '-'){
            return x-y;
        }
        if(op == '*'){
            return x*y;
        }
        return x/y;
    }
    int calculate(string str) {
        char prevOper = '+';
        stack<pair<int,char>> s;
        int curr = 0;
        int prev = 0;
        for(int i=0;i<str.size();i++){
            if(str[i] == '('){
                s.push({prev,prevOper});
                s.push({1,'('});
                curr = 0;
                prev = 0;
                prevOper = '+';
            }else{
                if(isdigit(str[i])){
                    curr = curr*10+(str[i]-'0');
                }else{
                    if(str[i] == '+' || str[i] == '-'){
                        curr = eval(prev,curr,prevOper);
                        while(!s.empty() && s.top().second != '('){
                            curr = eval(s.top().first,curr,s.top().second);
                            s.pop();
                        }
                        prev = curr;
                        prevOper = str[i];
                        curr = 0;
                    }else if(str[i] == '*'){
                        if(prevOper == '/'){
                            curr = eval(prev,curr,prevOper);
                            while(!s.empty() && (s.top().second == '/')){
                                curr = eval(s.top().first,curr,s.top().second);
                                s.pop();
                            }
                            prev = curr;
                            prevOper = str[i];
                            curr = 0;
                        }else{
                            s.push({prev,prevOper});
                            prev = curr;
                            prevOper = str[i];
                            curr = 0;
                        }
                    }else if(str[i] == '/'){
                        if(prevOper == '/' || prevOper == '*'){
                            curr = eval(prev,curr,prevOper);
                            while(!s.empty() && (s.top().second == '/' || s.top().second == '*')){
                                curr = eval(s.top().first,curr,s.top().second);
                                s.pop();
                            }
                            prev = curr;
                            prevOper = str[i];
                            curr = 0;
                        }else{
                            s.push({prev,prevOper});
                            prev = curr;
                            prevOper = str[i];
                            curr = 0;
                        }
                    }else{
                        curr = eval(prev,curr,prevOper);
                        
                        while(!s.empty() && s.top().second != '('){
                            curr = eval(s.top().first,curr,s.top().second);
                            s.pop();
                        }
                        // cout<<curr<<endl;
                        s.pop();
                        if(!s.empty()){    
                            prev = s.top().first;
                            prevOper = s.top().second;
                            s.pop();
                        }else{
                            prev = 0;
                            prevOper = '+';
                        }
                    }
                    
                }
            }
        }
                    
        curr = eval(prev,curr,prevOper);
        while(!s.empty() && s.top().second != '('){
            curr = eval(s.top().first,curr,s.top().second);
            s.pop();
        }
            
        return curr;
    }
};