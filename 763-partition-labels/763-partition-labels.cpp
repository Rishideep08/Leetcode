class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int start = 0;
        vector<int> res;
        unordered_map<char,int> um;
        for(int i=0;i<n;i++){
            um[s[i]] = i;
        }
        int next = 0;
        for(int i=0;i<n;i++){
            next = max(um[s[i]],next);
            if(i==next){
                res.push_back(i-start+1);
                start = i+1;
                
            }
            
        }
        return res;
        
    }
};