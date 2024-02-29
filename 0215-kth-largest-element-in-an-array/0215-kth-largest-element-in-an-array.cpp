class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k-1,0,nums.size()-1);
    }
    
    int quickSelect(vector<int>& nums, int k,int l,int r) {
        // cout<<"l : "<<l<<" r: "<<r<<endl;
        int size = r-l+1;
        int pivotIndex = (rand() % size)+l;
        swap(nums[pivotIndex],nums[r]);
        int pivot = nums[r];
        // cout<<pivotIndex<<" "<<nums[r]<<endl;
        int j = l-1;
        int i = l;
        while(l<r){
            if(nums[l]>pivot){
                j++;
                swap(nums[l],nums[j]);
            }
            l++;
        }
        j++;
        swap(nums[j],nums[r]);
//         for(int i=0;i<nums.size();i++){
//             cout<<nums[i]<<" ";
//         }
//         cout<<endl;
        
        if(j<k){
            return quickSelect(nums,k,j+1,r);
        }else if(j>k){
            return quickSelect(nums,k,i,j-1);
        }
            
        return nums[j];
    }
};