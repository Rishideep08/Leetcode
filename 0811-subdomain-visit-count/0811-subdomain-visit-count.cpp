class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>um;
        for(string domain :  cpdomains){
            int i = domain.find(" ");
            int val = stoi(domain.substr(0,i));
            while(i != string::npos ){
                um[domain.substr(i+1)]+=val;
                i = domain.find(".",i+1);
            }
        }
        vector<string> ans;
        for(auto itr= um.begin();itr!=um.end();itr++){
            string temp = to_string(itr->second);
            temp = temp +" ";
            temp+=itr->first;
            ans.push_back(temp);
        }
        return ans;
    }
};