class Solution {
public:
    vector<vector<int>>dp;
    int minDistance(string word1, string word2) {
       dp =  vector<vector<int>>(word1.size()+1,vector<int>(word2.size()+1,0));
        
        for(int i=1;i<=word2.size();i++){
            dp[0][i] = i;
        }
        for(int i=1;i<=word1.size();i++){
            dp[i][0] = i;
        }
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                }
            }
        }
        string res="";
        int i = word1.size();
        int j = word2.size();
        
        while(i>0 && j>0){
            if(word1[i-1] == word2[j-1]){
                res+=word2[j-1];
                i--;
                j--;
            }else{
                if(dp[i-1][j] < dp[i-1][j-1] && dp[i-1][j] < dp[i][j-1] ){
                    res += 'D';
                    res += word1[i-1];
                    i--;
                }else if(dp[i][j-1] < dp[i-1][j-1] && dp[i][j-1] < dp[i-1][j]){
                    res += 'A';
                    res += word2[j-1];
                    j--;
                }else{
                    res += 'R';
                    res += word2[j-1];
                    j--;
                    i--;
                }
            }
        }
        
        cout<<res<<endl;
        return dp[word1.size()][word2.size()];
    }
};