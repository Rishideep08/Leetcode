class Solution {
public:
    struct comp1{
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            if(a.first == b.first){
                return a.second>b.second;
            }
            return a.first>b.first;
        }
    };

    static bool comp(vector<int> a,vector<int> b){
        if(a[0] == b[0]){
            if(a[1]==b[1]){
                return a[2]<b[2];
            }
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // sort(tasks.begin(),tasks.end(),comp);
        // Store task enqueue time, processing time, index.
        vector<vector<int>> sortedTasks;
        for (int i = 0; i < tasks.size(); ++i) {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(sortedTasks.begin(), sortedTasks.end());
        
        // for(int i=0;i<sortedTasks.size();i++){
        //     cout<<sortedTasks[i][0]<<" "<<sortedTasks[i][1]<<" "<<sortedTasks[i][2]<<endl;
        // }
        
        int nextEndTime = sortedTasks[0][0];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        int i=0;
        vector<int> res;
        while(i<sortedTasks.size()){
            while(i<sortedTasks.size() && sortedTasks[i][0]<=nextEndTime){
                // cout<<sortedTasks[i][1]<<" "<<<<endl;
                pq.push({sortedTasks[i][1],sortedTasks[i][2]});
                i++;
            }
            if(pq.empty()){
                if(i<sortedTasks.size())
                    nextEndTime = sortedTasks[i][0];
                continue;
            }
            pair<int,int> temp = pq.top();
            pq.pop();
            nextEndTime = nextEndTime + temp.first;
            res.push_back(temp.second);
            
        }
        while(!pq.empty()){
             pair<int,int> temp = pq.top();
             pq.pop();
             res.push_back(temp.second);
        }
        
        return res;
    }
};