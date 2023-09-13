class Solution {
public:
    int calculate(vector<int>&weights,int m){
        int sum = 0;
        int count = 1;
        for(int weight :weights){
            if(weight>m){
                return INT_MAX;
            }
            if(sum+weight<=m){
                sum = sum +weight;
            }else{
                sum = weight;
                count++;
            }
        }
        return count;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0;
        int r = 1e9;
        int n = weights.size();
        if(n==0){
            return 0;
        }
        int ans = 0;
        while(l<=r){
            int m = l+(r-l)/2;
            if(calculate(weights,m)<=days){
                ans = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};