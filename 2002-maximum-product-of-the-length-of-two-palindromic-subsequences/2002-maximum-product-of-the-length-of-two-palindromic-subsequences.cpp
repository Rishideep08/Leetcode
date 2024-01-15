class Solution {
public:
    int maxVal=1;
    bool isPalindrome(string s){
        int i = 0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void func(string &s,int index,string &s1,string &s2){
        if(index == s.size()){
            if(isPalindrome(s1)&& isPalindrome(s2)){
                int x = s1.size()*s2.size();
                maxVal = max(maxVal,x);
            }
            return;
        }
        
        s1.push_back(s[index]);
        func(s,index+1,s1,s2);
        s1.pop_back();
        
        
        s2.push_back(s[index]);
        func(s,index+1,s1,s2);
        s2.pop_back();
        
        
         func(s,index+1,s1,s2);
    }
    
    
    int maxProduct(string s) {
        int n = s.size();
        if(n==0 || n==1){
            return 0;
        }
        string s1;
        string s2;
        func(s,0,s1,s2);
        return maxVal;
    }
};