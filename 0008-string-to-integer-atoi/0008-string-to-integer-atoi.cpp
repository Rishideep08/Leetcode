class Solution {
public:
    int myAtoi(string s) {
        int ans  = 0;
        int min = INT_MIN;
        int max = INT_MAX;
        bool isNeg = false;
        bool found = false;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])||s[i]=='-'||s[i]=='+'){
                if(s[i] == '-'){
                    if(found == true){
                        return ans;
                    }
                    isNeg = true;
                    found = true;
                }else if(s[i] == '+'){
                    if(found == true){
                        return ans;
                    }
                    isNeg = false;
                    found = true;
                }else{
                    found = true;
                    if(isNeg){
                        int digit = s[i]-'0';
                        int temp = (min+digit)/10;
                        if(temp<=ans){
                            ans = ans*10-digit;
                        }else{
                            ans = INT_MIN;
                            return ans;
                        }
                    }else{
                        int digit = s[i]-'0';
                        int temp = (max-digit)/10;
                        if(temp>=ans){
                            ans = ans*10+digit;
                        }else{
                            ans = INT_MAX;
                            return ans;
                        }
                    }
                }
            }else{
                if(found == true){
                    return ans;
                }
                if(s[i]!=' '){
                    break;
                }
            }
        }
        return ans;
    }
};