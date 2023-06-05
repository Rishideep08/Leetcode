class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        
        unordered_map<int,int>::iterator itr;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(itr = um.begin();itr!=um.end();itr++){
            pq.push({itr->second,itr->first});
            // cout<<itr->second<<" "<<itr->first<<endl;
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(pq.size()>0){
            int val = pq.top().second;
            ans.push_back(val);
            pq.pop();
        }
        
        
        return ans;
    }
};