class Solution {
public:
    int func(vector<string>& wordsDict, string word1, string word2){
        int w1 = -1,w2 = -1;
        int ans = INT_MAX;
        for(int i=0;i<wordsDict.size();i++){
            if(wordsDict[i]==word1){
                w1 = i;
            }else{
                if(w1 != -1 && wordsDict[i] == word2)
                    ans = min(ans,i-w1);
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        return min(func(wordsDict,word1,word2),func(wordsDict,word2,word1));
    }
};