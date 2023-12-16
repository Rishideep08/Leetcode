class Solution {
public:
    int pathSum(vector<int>& nums) {
        unordered_map<int,unordered_map<int,int>> um;
        for(int num : nums){
            if(um.find(num/100) == um.end()){
                unordered_map<int,int> um1;
                um[num/100] = um1;
            }
            um[num/100][(num/10)%10] = num%10;
        }
        unordered_map<int,int> um1;
        um[5] = um1;
        int ans = 0;
        for(int i=1;i<5;i++){
            for(auto it = um[i].begin();it != um[i].end();it++){
                int key = it->first;
                int val = it->second;
                int flag = 0;
                if(um[i+1].find(2*key) != um[i+1].end()){
                    um[i+1][2*key] += val;
                    flag = 1;
                } 
                if(um[i+1].find(2*key-1) != um[i+1].end()){
                    um[i+1][2*key-1] += val;
                    flag = 1;
                } 
                if(flag == 0){
                    ans = ans +val;
                }
            }
        }
        return ans;
    }
};