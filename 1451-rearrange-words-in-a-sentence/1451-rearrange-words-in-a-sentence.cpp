class Solution {
public:
    static bool comp(pair<string,int>&a, pair<string,int>&b ){
        if( (a.first).size() == (b.first).size()){
            return a.second<b.second;
        }
        return (a.first).size()<(b.first).size();
    }
    string arrangeWords(string text) {
        text[0] = text[0]-'A'+'a';
        stringstream ss(text);
        string word;
        vector<pair<string,int>> temp;
        int i =0;
        while(getline(ss,word,' ')){
            temp.push_back({word,i});
            i++;
        }
        
        sort(temp.begin(),temp.end(),comp);
        string res = "";
        for(int i=0;i<temp.size();i++){
            res+=temp[i].first;
            res+=' ';
        }
        res = res.substr(0,res.size()-1);
        res[0] = res[0]-'a'+'A';
        return res;
    }
};