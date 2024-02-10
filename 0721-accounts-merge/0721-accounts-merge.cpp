class Solution {
public:
    unordered_map<string,string> primary;
    unordered_map<string,string> primaryToAccount;
    
    string findParent(string a){
        if(primary[a] == a){
            return a;
        }
        primary[a] = findParent(primary[a]);
        return primary[a];
    }
    
    void unionPrimary(string a,string b){
        string pa = findParent(a);
        string pb = findParent(b);
        if(pa != pb){
            primary[pb]=pa;   
            primaryToAccount.erase(pb);
        }
        return;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(primary.find(accounts[i][j]) == primary.end()){
                    primary[accounts[i][j]] = accounts[i][j];
                    primaryToAccount[accounts[i][j]] = accounts[i][0];
                }
                if(j!=1){
                    unionPrimary(accounts[i][j-1],accounts[i][j]);
                }
            }
        }
        unordered_map<string,vector<string>> primaryToDuplicates;
        for(auto itr = primary.begin();itr!=primary.end();itr++){
            string primary = findParent(itr->first);
            primaryToDuplicates[primary].push_back(itr->first);
        }
        vector<vector<string>> ans;
        for(auto itr = primaryToDuplicates.begin();itr!=primaryToDuplicates.end();itr++){
            vector<string> temp = itr->second;
            sort(temp.begin(),temp.end());
            temp.insert(temp.begin(),primaryToAccount[itr->first]);
           ans.push_back(temp);
        }
        return ans;
    }
};