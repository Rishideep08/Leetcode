class Solution {
public:
    long long calculateWays(vector<long long> temp){
        long long int val = 0;
        long long n = temp.size();
        if(n<=2){
            if(n==0){
                return 0;
            }
            return n+1;
        }
        vector<long long> dp(n,0);
        dp[0] = 2;
        dp[1] = 3;
        for(long long i=2;i<temp.size();i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        val = dp[n-1];
        return val;
    }
    
    long long countTheNumOfKFreeSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        map<long long ,long long> um;
        // int maxVal = nums[nums.size()-1];
        for(long long i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        // cout<<"HI adfb "<<um.size()<<endl;
        vector<long long> res;
        while(um.size()>0){
            auto itr = um.begin();
            int start = itr->first;
            vector<long long> temp;
            while(um.find(start)!= um.end()){
                // cout<<" itr "<< start<<endl;
                temp.push_back(start);
                um[start]--;
                if(um[start] == 0){
                    um.erase(start);
                }
                start = start+k;
            }
            // cout<<um.size()<<" adb "<<endl;
            res.push_back(calculateWays(temp));
            
        }
        // cout<<res.size()<<endl;
        long long int ans = 1;
        for(int i=0;i<res.size();i++){
            ans = ans*res[i];
        }
        
        return ans;
        
        
    }
};