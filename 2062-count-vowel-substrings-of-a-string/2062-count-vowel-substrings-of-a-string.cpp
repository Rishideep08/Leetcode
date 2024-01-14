class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_map<char,int> um;
        int curr = 0;
        int start = 0;
        int end = 0;
        int possibleStarts =0;
        int res = 0;
        int prev =0 ;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(ch=='a'|| ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                um[ch]++;
                // int flag = 0;
                while(um.size() == 5){
                    // cout<<i<<" "<<start<<endl;
                    // flag = 1;
                    possibleStarts++;
                    um[word[start]]--;
                    if(um[word[start]]==0){
                        um.erase(word[start]);
                    }
                    start++;
                }  
                curr = prev+ possibleStarts;
                // if(flag == 1){
                //     curr--;
                // }
                res = res+curr;
                // if(res == 1){
                //     cout<<start<<" "<<i<<endl;
                // }
                prev = curr;
                possibleStarts = 0;
            }else{
                start = i+1;
                possibleStarts = 0;
                prev = 0;
                um.clear();
            }
        }
        return res;
    }
};