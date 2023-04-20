class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> um;
        
        
        for(int i=0;i<tasks.size();i++){
            um[tasks[i]]++;
        }
        
        priority_queue<pair<int,char>> pq;
        for(auto itr = um.begin();itr!=um.end();itr++){
            pq.push({itr->second,itr->first});
        }
        int res=0;
        n++;
        while(!pq.empty()){
            vector<pair<int,char>> temp;
            int count =0;
            while(!pq.empty() && count<n){
                temp.push_back( pq.top());
                // cout<<pq.top().first<<" "<<pq.top().second<<endl;
                pq.pop();
                count++;
            }
            for(int i=0;i<temp.size();i++){
                if(temp[i].first != 1){
                    pq.push({temp[i].first-1,temp[i].second});
                }
            }
            
            if(pq.empty()){
                res = res+count;
            }else{
                res = res+n;
            } 
            // cout<<"res "<<res<<endl;
        }
        
        return res;
        
        
    }
};