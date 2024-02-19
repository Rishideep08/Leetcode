class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long int ans=0;
        unordered_map<int,long long int> um;
        for(int i=0;i<tasks.size();i++){
            if(um.find(tasks[i]) == um.end()){
                ans++;
                um[tasks[i]] = ans;
            }else{
                ans = max(um[tasks[i]]+space,ans);
                ans++;
                um[tasks[i]] = ans;
            }
        }
        return ans;
    }
};