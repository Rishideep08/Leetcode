class Solution {
public:
    vector<string> ans;
    unordered_map<int,vector<string>> um;
    
    vector<string> func(int n ){
        if(n==0){
            vector<string> temp;
            temp.push_back("");
            return temp;
        }
        
        if(n==1){
           vector<string> temp;
            temp.push_back("()"); 
            return temp;
        }
        if(um.find(n) != um.end()){
            return um[n];
        }
        
        vector<string> ans;
        for(int i=0;i<=n-1;i++){
            vector<string> inner = func(i);
            vector<string> outer = func(n-1-i);
            string res ="(";
            for(int j=0;j<inner.size();j++){
                string res1= res+inner[j];
                res1 = res1+')';
                for(int k=0;k<outer.size();k++){
                    string res2 = res1+outer[k];
                    ans.push_back(res2);
                }
                
            }
        }
        um[n] = ans;
        return ans;
    }
    
    
    
    vector<string> generateParenthesis(int n) {
        
        return func(n);
    }
};