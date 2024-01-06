class Solution {
public:
    string reverseWords(string str) {
        stringstream ss(str);
        string word;
        string ans = "";
        while(getline(ss,word,' ')){
            reverse(word.begin(),word.end());
            ans = ans + word;
            ans = ans + " ";
        }
        return ans.substr(0,ans.size()-1);
        
    }
};