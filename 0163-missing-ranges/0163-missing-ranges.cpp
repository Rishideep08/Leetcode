class Solution {
public:
    
    vector<int> func(int l,int r){
        vector<int> temp;
        temp.push_back(l);
        temp.push_back(r);
        return temp;
    }
    
    
    vector<vector<int>> findMissingRanges(vector<int>& nums, int l, int r) {
        vector<vector<int>> res;
        int flag = 0;
        int n = nums.size();
        for(int i =0;i<nums.size();i++){
            if(nums[i]>=l && nums[i]<=r){
                flag = 1;
                if(i==0){
                    if(l<=nums[i]-1)
                        res.push_back(func(l,nums[i]-1));
                }else if(nums[i-1]<l){
                    if(l<=nums[i]-1)
                        res.push_back(func(l,nums[i]-1));
                }
                
                if(i+1 == n){
                     if(nums[i]+1<=r)
                        res.push_back(func(nums[i]+1,r));
                }else if (nums[i+1]>r){
                    if(nums[i]+1<=r)
                        res.push_back(func(nums[i]+1,r));
                }else{
                    if(nums[i]+1<=nums[i+1]-1)
                        res.push_back(func(nums[i]+1,nums[i+1]-1));
                }    
            }

        }
        
        if(flag == 0){
                res.push_back(func(l,r));
          }
        return res;
    }
};