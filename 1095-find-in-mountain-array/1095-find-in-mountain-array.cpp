/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int doBinarySearch(MountainArray &mountainArr,int l,int r,int target,int leftFlag){
        int ans = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            int val = mountainArr.get(m);
            if(val == target){
                ans = m;
                r=m-1;
            }else{
                if(leftFlag == 1){
                    if(val<target){
                        l = m+1;
                    }else{
                        r = m-1;
                    }   
                }else{
                    if(val>target){
                        l = m+1;
                    }else{
                        r = m-1;
                    }
                }

            }
        }
        return ans;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0;
        int r = n-1;
        int ans = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            int val = mountainArr.get(m);
            // cout<<l<<" "<<r<<" "<<m<<" "<<val<<endl;
            if( val == target){
                ans = m;
                r = m-1;
            }else{
                int prev = INT_MIN;
                if(m!=l){
                    prev = mountainArr.get(m-1);
                }
                int next = INT_MIN;
                if(m!=r){
                    next = mountainArr.get(m+1);
                }
                
                if(val>prev && val>next){
                    int index = doBinarySearch(mountainArr,l,m-1,target,1);
                    if(index !=-1){
                        return index;
                    }
                    index = doBinarySearch(mountainArr,m+1,r,target,0);
                    if(index !=-1){
                        return index;
                    }
                    return ans;
                }
                // cout<<"HI "<<prev<<" "<<val<<" "<<next<<endl; 
                if(val>prev && next>val){
                    if(target<val){
                       int index = doBinarySearch(mountainArr,l,m-1,target,1);
                        if(index != -1){
                            ans = index;
                            return ans;
                        }
                    }
                    l = m+1;
                }else if(val<prev && next<val){
                    if(target<val){
                        int index = doBinarySearch(mountainArr,m+1,r,target,0);
                        if(index != -1){
                            ans = index;
                        }
                    }
                    r = m-1;
                }
            }
        }
        
        return ans;
    }
};