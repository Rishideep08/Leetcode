class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;
        int maxVal = nums[0];
        int l = nums.size();
        int r = nums.size();
        s.push(0);
        int flag = 1 ;
        for(int i=1;i<nums.size();i++){
            while(!s.empty() && nums[s.top()]>nums[i]){
                maxVal = max(maxVal,nums[s.top()]);
                l = min(l,s.top());
                flag = 0;
                s.pop();
            }
            if(nums[i]>=maxVal){
                if(flag == 0){
                    r = i;
                    flag = 1;
                }
                s.push(i);
            }  
            
            // cout<<l<<endl;
        }
        if(flag == 0){
            r = nums.size();
        }
        
        // cout<<l<<" "<<r<<endl;
        
        return r-l;
    }
};