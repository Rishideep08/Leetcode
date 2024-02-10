class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int incomeLeft = income;
        double ans =0;
        int prev =0;
        for(int i=0;i<brackets.size();i++){
            incomeLeft = income-prev;
            if((brackets[i][0]-prev)>=incomeLeft){
                ans = ans + (incomeLeft*1.0)*(brackets[i][1]/100.0);
                return ans;
            }else{
                ans = ans+(brackets[i][0]-prev)*(brackets[i][1]/100.0);
                prev = brackets[i][0];
            }
        }
        return ans;
    }
};