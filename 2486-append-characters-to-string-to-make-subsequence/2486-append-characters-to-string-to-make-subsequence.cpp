class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        int i=0,j=0;
        
        while( j<m){
            while(i<n && s[i] != t[j]){
                i++;
            }
            if(i==n){
                return m-j;
            }
            
            i++;
            j++;
        }
        return 0;
    }
};