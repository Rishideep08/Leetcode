class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int temp = 0;
                if(prices[j]<=prices[i]){
                    temp = prices[i]- prices[j];
                    if(j>2){
                        temp = temp+dp[j-2];
                    }
                    dp[i] = max(dp[i],temp);
                }
            }
            if(i>1)
                dp[i] = max(dp[i],dp[i-1]);
        }
        int maxValue = 0;
        for(int i=0;i<n;i++){
            maxValue = max(maxValue,dp[i]);
        }
        return maxValue;
    }
};