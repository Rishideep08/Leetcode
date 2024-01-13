class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int n = brackets.size();
        if(n==0){
            return 0;
        }
        int i=0;
        int prev =0;
        double ans = 0;
        while(income>brackets[i][0]){
            ans += (brackets[i][0]-prev)*(brackets[i][1]/100.0);
            prev = brackets[i][0];
            i++;
        }
        ans+=(income-prev)*(brackets[i][1]/100.0);
        return ans;
    }
};