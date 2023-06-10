class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<int,vector<int>,greater<int>> room_priority;
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
        for(int i=0;i<n;i++){
            room_priority.push(i);
        }
        vector<int> lookup(meetings.size(),0);
        vector<int> res(n,0);
        for(int i=0;i<meetings.size();i++){
            while(!pq.empty() && meetings[i][0]>=pq.top().first){
                int j = pq.top().second;
                pq.pop();
                // room_priority.push(lookup[j]);
                 room_priority.push(j);
            }
            
            if(!room_priority.empty()){
                int room = room_priority.top();
                room_priority.pop();
                res[room]++;
                pq.push({meetings[i][1],room});
            }else{
                int j = pq.top().second;
                long long int delay =pq.top().first-meetings[i][0];
                pq.pop();
                // lookup[i] = lookup[j];
                res[j]++;
                pq.push({meetings[i][1]+delay,j});
            }
        }
        
        // vector<int> res(n,0);
        // for(int i=0;i<meetings.size();i++){
        //     res[lookup[i]]++;
        // }
        int ans = 0;
        int val = 0;
        for(int i=0;i<n;i++){
            if(val<res[i]){
                val = res[i];
                ans = i;
            }
        }
        
        return ans;
        
    }
};