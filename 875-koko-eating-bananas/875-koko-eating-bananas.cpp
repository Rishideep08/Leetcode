class Solution {
public:
    
    bool check(vector<int>& piles, int h,int k){
        for(int i=0;i<piles.size();i++){
            int val = piles[i]/k;
            if(piles[i]%k !=0){
                val++;
            }
            h = h-val;
            if(h<0){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r =  *max_element(piles.begin(),piles.end());
        int l = 1;
        int ans = 1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(check(piles,h,m) == true){
                ans = m; 
                r = m-1;
            }else{
                l = m+1;
            }
        }
        
        return ans;
        
    }
};