class Solution {
public:
    bool check(vector<int>&possible,vector<int>&lookup){
        for(int i=0;i<100;i++){
            if(possible[i] < lookup[i] && lookup[i]!=0){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(t == "" || s.size()<t.size()){
            return "";
        }
        int start = 0;
        int end = 0;
        vector<int> lookup(100,0),possible(100,0);
        for(int i=0;i<t.size();i++){
            int j = t[i]-'A';
            // cout<<j<<endl;
            lookup[j]++;
        }
        int n = s.size();
        int final_i=-1;
        int final_j=-1;
        int minLen = INT_MAX;
        while(end<n){
            possible[s[end]-'A']++;
            while(check(possible,lookup)){
                if(end-start+1<minLen){
                    final_i = start;
                    final_j = end;
                    minLen = end-start+1;
                    // cout<<"HI"<<endl;
                }
                possible[s[start]-'A']--;
                start++;
            }
            end++;
        }
        if(minLen == INT_MAX){
            return "";
        }
        return s.substr(final_i,final_j-final_i+1);
    }
};