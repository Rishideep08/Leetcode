class Solution {
public:
    vector<vector<int>> dp;
    int func(vector<int>& tasks,int sessionTime,int remainTime,int index,int mask){
        if(index == tasks.size()){
            return 0;
        }
        if( dp[mask][remainTime] != -1){
            return dp[mask][remainTime];
        }
        
        int ans = tasks.size();
        for(int i=0;i<tasks.size();i++){
            if((mask & (1<<i)) == 0){
                ans = min(ans,func(tasks,sessionTime,sessionTime-tasks[i],index+1,mask | (1<<i))+1);
                if(remainTime>=tasks[i]){
                    ans = min(ans,func(tasks,sessionTime,remainTime-tasks[i],index+1,mask | (1<<i)));
                }
            }
        }
        
        dp[mask][remainTime] = ans;
        return ans;
        
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        dp = vector<vector<int>>(1e5,vector<int>(20,-1));
        return func(tasks,sessionTime,0,0,0); 
    }
};