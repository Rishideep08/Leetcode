class Solution {
public:
    bool checkPredecessor(string word1,string word2){
        for(int i=0;i<word1.size();i++){
            string temp = word1.substr(0,i)+word1.substr(i+1);
            if(word2 == temp){
                return true;
            }
        }
        return false;
    }
    static bool comp(string word1,string word2){
        return word1.size()<word2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n =  words.size();
        if(n==0){
            return 0;
        }
        sort(words.begin(),words.end(),comp);
        unordered_map<string,int> dp;
        dp[words[0]] = 1;
        int maxVal = 1;
        
        for(int i=1;i<n;i++){
            dp[words[i]] = 1;
            for(int j=0;j<words[i].size();j++){
                string possiblePredecessor = (words[i]).substr(0,j)+(words[i]).substr(j+1);
                // string temp = 
                if(dp.find(possiblePredecessor) != dp.end()){
                    dp[words[i]] = max(dp[words[i]],dp[possiblePredecessor]+1);
                }
            }
            maxVal = max(maxVal,dp[words[i]]);
        }    
        return maxVal;
    }
};