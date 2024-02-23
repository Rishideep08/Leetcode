class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = s.size()-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                start = i;
                break;
            }
        }
        
        int count =0;
        while(start>=0 && s[start]!=' '){
            count++;
            start--;
        }
        return count;
    }
};