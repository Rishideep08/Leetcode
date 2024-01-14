class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_map<char,int> um;
        int ans = 0;
        for(int i=0;i<word.size();i++){
            um.clear();
            for(int j=i;j<word.size();j++){
                char ch = word[j];
                if(ch == 'a' || ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                    um[ch]++;
                }else{
                    break;
                }
                if(um.size()==5){
                    ans++;
                }
            }
        }
        return ans;
    }
};