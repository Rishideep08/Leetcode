class Solution {
public:
    static bool compare(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
        
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {   
        vector<pair<int,int>> temp;
        for(int i=0;i<flowers.size();i++){
            temp.push_back({flowers[i][0],1});
            temp.push_back({flowers[i][1],-1});
        }
        unordered_map<int,vector<int>> um;
        for(int i=0;i<people.size();i++){
           um[people[i]].push_back(i);
        }
       
        
        for(int i=0;i<people.size();i++){
            temp.push_back({people[i],0});
        }
                           
        sort(temp.begin(),temp.end(),compare);
        vector<int> ans(people.size(),0); 
        int count = 0;
        for(int i=0;i<temp.size();i++){
            if(temp[i].second == 1){
                count++;
            }else if(temp[i].second == -1){
                count--;
            }else{
                vector<int>&x = um[temp[i].first];
                int index = x[x.size()-1];
                x.pop_back();
                ans[index] = count;
            }
        }
    
        return ans;
    }
};