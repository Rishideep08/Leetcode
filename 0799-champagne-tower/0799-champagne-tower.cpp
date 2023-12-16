class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(1,0.0);
        int level = 0;
        int counsumed = 0;
        dp[0] = poured;
        while(level<query_row ){
            dp.push_back(0.0);
            int flag = 0;
            for(int i=dp.size()-2;i>=0;i--){
                double extra = dp[i]-1;
                extra = max(0.0,extra);
                if(extra > 0.0){
                    flag = 1;
                }
                dp[i+1] += extra/2;
                dp[i] = extra/2; 
            }
            if(flag == 0){
               break;
            }
            level++;
        }
        if(query_row>level){
            return 0;
        }
        return min(dp[query_glass],1.0);
        
        
    }
};