class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i=0;
        int j=0;
        int n = word.size();
        int m = abbr.size();
        int num = 0;
        while(i<n && j<m){
            if(!isdigit(abbr[j])){
                i = i+num;
                if(i>=n){
                    return false;
                }
                num = 0;
                if(word[i] != abbr[j]){
                    return false;
                }
                i++;
                j++;
            }else{
                if(abbr[j]=='0'){
                    if(num == 0){
                        return false;
                    }
                }
                num = num*10+(abbr[j]-'0');
                j++;
            }
        }
        
        i = i+num;
        if(i==n && j==m){
            return true;
        }
        return false;
    }
};