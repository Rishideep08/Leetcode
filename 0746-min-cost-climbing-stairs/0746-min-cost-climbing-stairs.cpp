class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int maxCovered=0;
        int a=0, b=0;
        for(int i=2;i<cost.size()+1;i++){
           int temp = min(a+cost[i-2],b+cost[i-1]);
            a = b;
            b = temp;
        }
        
        return b;
    }
};