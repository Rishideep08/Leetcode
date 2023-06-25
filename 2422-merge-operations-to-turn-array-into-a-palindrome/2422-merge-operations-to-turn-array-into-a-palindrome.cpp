class Solution {
private:
public:
    
    
    int minimumOperations(vector<int>& nums) {
        
        int i = 0;
        int j = nums.size()-1;
        int count =0;
        
        while(i<=j){
            if(nums[i] == nums[j]){
                i++;
                j--;
            }else if(nums[i] > nums[j]){
                count++;
                nums[i] = nums[i]-nums[j];
                j--;
            }else{
                count++;
                nums[j] = nums[j]-nums[i];
                i++;
            }
        }
        
        return count;
        
    }
};