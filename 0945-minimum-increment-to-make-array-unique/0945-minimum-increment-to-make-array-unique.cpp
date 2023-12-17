class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(),nums.end());
        vector<int> count(nums.size()+maxVal);
        for(int num : nums){
            count[num]++;
        }
        int ans = 0;
        int x=0;
        for(int num = 0;num<count.size();num++){
            if(count[num]>=2){
                ans = ans - num*(count[num]-1);
                x = x+count[num]-1;
            }else if(x>0 && count[num] == 0){ 
                x--;
                ans = ans + num;
            }
        }
        
        return ans;
        
    }
};