class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> um;
        for(int i=0;i<tasks.size();i++){
            um[tasks[i]]++;
        }
        int ans = 0;
        for(auto itr= um.begin();itr!=um.end();itr++){
            if(itr->second == 1){
                return -1;
            }
            if(itr->second%3 == 0){
                ans=ans + itr->second/3;
            }else{
                ans = ans + itr->second/3 +1;
            }
        
        }
        return ans;
        
    }
};