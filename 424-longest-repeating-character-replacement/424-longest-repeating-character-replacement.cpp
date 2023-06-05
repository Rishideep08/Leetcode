class Solution {
public:
    int helper(string s,int k,char ch){
        int start = 0;
        int end = 0;
        int ans = 0;
        int n = s.size();
        while(end<n){
            if(s[end] != ch){
                k--;
            }

            while(k<0){
               if(s[start] != ch){
                   k++;
               }
               start++;
            }
            
            ans = max(ans,end-start+1);

            end++;
        }
        return ans;
    }
    
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(int i=0;i<26;i++){
            char ch = 'A'+i;
            ans = max(ans,helper(s,k,ch));
        }
        return ans;
    }
};