class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> digits(10,0);
        for(char ch : num){
            digits[ch-'0']++;
        }
        string res;
        char extraChar = ' ';
        int flag = 0;
        for(int i=9;i>=0;i--){
           int x =  digits[i]/2;
            while(x){
                char ch = (i+'0');
                if(i== 0 && res == ""){
                    break;
                }
                x--;
                res+=ch;
            }
            if(digits[i]%2 == 1 && flag == 0){
                flag = 1;
                extraChar = i+'0';
            }
            if(flag == 0 && i==0 && digits[i]!=0 && res ==""){
                return "0";
            }
        }
        string ans=res;
        reverse(res.begin(),res.end());
        if(extraChar != ' '){
            ans = ans + extraChar;
        }
        ans = ans + res;
        return ans;
        
    }
};