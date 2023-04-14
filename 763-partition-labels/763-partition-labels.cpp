class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        
        unordered_map<char,int> um;
        for(int i=0;i<n;i++){
            um[s[i]] = i;
        }
        
        vector<int> res;
        int start = 0;
        
        for(int i=0;i<n;i++){
            bool flag = true;
            for(int j=0;j<i;j++){
                if(um[s[j]]>=i){
                    flag = false;
                    break;
                }
            }
            
            if(flag == true && i!=0){
                res.push_back(i-start);
                start = i;
            }
        }
        
        res.push_back(n-start);
        return res;
    }
};