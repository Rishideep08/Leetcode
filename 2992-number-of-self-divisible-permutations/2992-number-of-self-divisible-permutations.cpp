class Solution {
public:
    int count = 0;
    int gcd(int a,int b){
        if(a<b){
            return gcd(b,a);
        }
        
        if(b==0){
            return a;
        }
        
        return gcd(a%b,b);
    }
    
    int generatePermutations(int n,int index,vector<int>&dp,int mask){
        if(index == n){
            return 1;
        }
        if(dp[mask] != -1){
            return dp[mask];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if((mask&(1<<i))==0){
                if(gcd(index+1,i+1) == 1){
                    ans = ans + generatePermutations(n,index+1,dp,(mask|(1<<i)));
                }
            }
        }
        dp[mask] = ans;
        return ans;
    }
    int selfDivisiblePermutationCount(int n) {
        vector<int> dp = vector<int>(1<<(n),-1);
        return generatePermutations(n,0,dp,0);
        
    }
};