// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int ans = l;
        while(l<=r){
            int m = l+(r-l)/2;
            if(isBadVersion(m)==true){
                ans = m;
                r = m-1;
            }else{
                l = m+1;
            }
            
        }
        return ans;
    }
};