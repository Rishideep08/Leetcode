class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        vector<pair<int,pair<int,string>>> lookup;
        for(int i=0;i<logs.size();i++){
            stringstream ss(logs[i]);
            string word;
            vector<string> temp;
            while(getline(ss,word,':')){
                temp.push_back(word);
            }
            int id = stoi(temp[0]);
            int time = stoi(temp[2]);
            lookup.push_back({time,{id,temp[1]}});
        }
        // sort(lookup.begin(),lookup.end());
        stack<pair<int,int>> prevId;
        int x = 0;
        for(int i=0;i<lookup.size();i++){
            
            if(lookup[i].second.second=="end"){
                int val = lookup[i].first-prevId.top().second+1;
                ans[lookup[i].second.first] += val;
                prevId.pop();
                // cout<<i<<" "<<val<<endl;
                
                if(!prevId.empty()){
                   prevId.top().second = lookup[i].first+1;
                }
            }else{
                // cout<<i<<" : "<<prevId.size()<<" "<<lookup[i].second.second<<endl;
                if(!prevId.empty()){
                    int val = lookup[i].first-prevId.top().second;
                    // cout<<i<<" "<<val<<endl;
                    ans[prevId.top().first] += val;
                }
                prevId.push({lookup[i].second.first,lookup[i].first});
            }
        }
        return ans;
    }
};