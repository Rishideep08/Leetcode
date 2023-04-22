class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while(fast != slow){
             // cout<<fast<<" "<<slow<<endl;
            fast = nums[nums[fast]];
            slow = nums[slow];
            
           
        }
        
        slow = nums[0];
        fast = nums[fast];
        while(fast != slow){
            // cout<<fast<<" "<<slow<<endl;
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return fast;
    }
};