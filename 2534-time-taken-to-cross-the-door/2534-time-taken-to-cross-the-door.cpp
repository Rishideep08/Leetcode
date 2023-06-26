class Solution {
public:
    pair<int,int> prev;
    int currtime = 0;
    queue<pair<int,int>> entry,exit;
    vector<int> res;
    
    void helper(){
        // cout<<prev.first<<" "<<currtime<<endl;
        if(prev.first != currtime-1){
            if(!exit.empty()){
                res[exit.front().second] = currtime;
                exit.pop();
                prev.first = currtime;
                prev.second = 1;
            }else{
                res[entry.front().second] = currtime;
                entry.pop();
                prev.first = currtime;
                prev.second = 0;
            }
        }else{
            if(prev.second == 0){
                if(!entry.empty()){
                    res[entry.front().second] = currtime;
                    entry.pop();
                    prev.first = currtime;
                    prev.second = 0;
                }else{
                    res[exit.front().second] = currtime;
                    exit.pop();
                    prev.first = currtime;
                    prev.second = 1;
                }
                
            }else{
                if(!exit.empty()){
                    res[exit.front().second] = currtime;
                    exit.pop();
                    prev.first = currtime;
                    prev.second = 1;
                }else{
                    res[entry.front().second] = currtime;
                    entry.pop();
                    prev.first = currtime;
                    prev.second = 0;
                }
            }
        }
    }
    
    
    
    
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        int n = arrival.size();
        prev = make_pair(-10,0);
        res = vector<int> (n,0);
        for(int i=0;i<arrival.size();i++){
            // cout<<i<<" abc "<<currtime<<endl;
            while(currtime != arrival[i] && (!entry.empty() || !exit.empty())){
                helper();
                currtime++;
            }
            
            if(entry.empty() && exit.empty()){
                currtime = arrival[i];
            }
            
            while(i<n && arrival[i] == currtime){
                if(state[i] == 1){
                    exit.push({arrival[i],i});
                }else{
                    entry.push({arrival[i],i});
                }
                i++;
            }
            i--;
            
            // cout<<i<<" "<<currtime<<endl;
            
            helper();
            currtime++;
        }
        // cout<<entry.size()<<" "<<exit.size()<<endl;
        
        while(!entry.empty() && !exit.empty()){
            helper();
            currtime++;
        }
        
        while(!entry.empty()){
            helper();
            currtime++;
            // entry.pop();
        }
        
        while(!exit.empty()){
            helper();
            currtime++;
            // exit.pop();
        }
        
        return res;
    }
};