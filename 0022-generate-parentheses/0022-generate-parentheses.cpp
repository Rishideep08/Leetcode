class Solution {
public:
    unordered_map<int,vector<string>>um;
    
    vector<string> func(int n ){
        if(n==0){
            vector<string> temp;
            return temp;
        }
        if(n==1){
            vector<string> temp;
            string ans = "()";
            temp.push_back(ans);
            return temp;
        }
        
        if(um.find(n) != um.end()){
            return um[n];
        }
        vector<string> ans;
        for(int i=0;i<n;i++){
            vector<string> temp1 = func(i);
            vector<string> temp2 = func(n-i-1);
            for(int j=0;j<temp1.size();j++){
                string ans1 = "(";
                ans1+=temp1[j];
                ans1+=')';
                for(int k=0;k<temp2.size();k++){
                    string ans2 = ans1+temp2[k];
                    ans.push_back(ans2);
                }
                if(temp2.size() == 0){
                    ans.push_back(ans1);
                }
            }
        }
         vector<string> temp2 = func(n-1);
        string ans1 = "(";
        ans1+=')';
        for(int k=0;k<temp2.size();k++){
            string ans2 = ans1+temp2[k];
            ans.push_back(ans2);
        }
        
        um[n] = ans;
        
        return ans;
        
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        return func(n);
        
        
    
        
    }
};