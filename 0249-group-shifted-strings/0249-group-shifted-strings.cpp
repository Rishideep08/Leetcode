class Solution {
public:
    string getSource(string s){
        int shift = s[0]-'a';
        string res="";
        for(int i=0;i<s.size();i++){
            char ch = (s[i]-shift+26)%26;
            res = res + ch;
        }
        return res;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> um;
        for(string s:strings){
            string temp = getSource(s);
            // cout<<s<<" : "<<temp<<endl;
            um[temp].push_back(s);
        }
        
        vector<vector<string>> res;
        for(auto itr=um.begin();itr!=um.end();itr++){
            res.push_back(itr->second);
        }
        return res;
    }
};