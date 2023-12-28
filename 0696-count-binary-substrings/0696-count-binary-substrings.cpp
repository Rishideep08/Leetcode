class Solution {
public:
    int func(char ch,string s){
        int ans = 0;
        int count =0;
        int n = s.size();
        int maxCount = 0;
        for(int i=0;i<n;i++){
            if(s[i] == ch){
                count++;
            }else{
                if(count !=  0){
                    maxCount = count;
                    count = 0;
                }
                if(maxCount>0){
                    ans++;
                    maxCount--;
                }
            }
        }
        return ans;
    }
    int countBinarySubstrings(string s) {
        
        return func('0',s)+func('1',s);
        
    }
};