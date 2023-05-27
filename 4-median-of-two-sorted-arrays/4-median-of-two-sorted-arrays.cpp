class Solution {
public:
    double func(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int m = nums2.size();
        int total = n+m;
        int half = total/2;
        int l = 0;
        int r = n-1;
        while(true){  
            int i =l+(r-l+1)/2;
            int j = half-i;
            cout<<i<<" "<<j<<endl;
            int l1 = INT_MIN;
            if(i>=1){
                l1 = nums1[i-1];
            }
            int r1 = INT_MAX;
            if(i<n){
                r1 = nums1[i];    
            }
            
            
            int l2 = INT_MIN;
            if(j>=1){
                l2 = nums2[j-1];
            }
            int r2 = INT_MAX;
            if(j<m){
                r2 = nums2[j];
            }
            
            // cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
            
            if(l1<=r2 && l2<=r1){
                if(total%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                return min(r1,r2);
            }else if(l1>r2){
                r = i-1;
            }else{
                // cout<<"HI"<<endl;
                l = i+1;
                // cout<<l<<" "<<r<<endl;
            }
        }
        
        return 1;
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return func(nums2,nums1);
        }
        return func(nums1,nums2);
    }
};