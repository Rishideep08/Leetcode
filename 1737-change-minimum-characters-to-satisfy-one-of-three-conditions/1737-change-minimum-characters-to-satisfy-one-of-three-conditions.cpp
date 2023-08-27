class Solution {
public:
    int minCharacters(string a, string b) {
        vector<vector<int>> lookup(2,vector<int>(26,0));
        
        for(int i=0;i<a.size();i++){
            lookup[0][a[i]-'a']++;
        }
        
        
        for(int i=0;i<b.size();i++){
            lookup[1][b[i]-'a']++;
        }
        int n = a.size();
        int m = b.size();
        int ans = n+m-lookup[0][0]-lookup[1][0];
        for(int i=1;i<26;i++){
            ans = min(ans,n+m-lookup[0][i]-lookup[1][i]);
            ans = min(ans,min(lookup[0][i-1]+m-lookup[1][i-1],n-lookup[0][i-1]+lookup[1][i-1]));
            lookup[0][i]+=lookup[0][i-1];
            lookup[1][i]+=lookup[1][i-1];
        }
        
        
        
    
        
        
        
        return ans;
    }
};