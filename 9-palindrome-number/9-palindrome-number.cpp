class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        if(x<10){
            return true;
        }
        if(x%10 ==0){
            return false;
        }
        long long int val = 0;
        while(x>0){
            int rem = x%10;
            x = x/10;
            if(x == val){
                return true;
            }
            val = val*10+rem;
            if(x == val){
                return true;
            }
        }
        return false;
    }
};