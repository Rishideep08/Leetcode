class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<int> s;
        for(int i=0;i<nums.size();i++){
            while(k>0 && !s.empty() && nums[s.top()]>nums[i]) {
                s.pop();
                k--;
            }
            s.push(i);
        }
        string ans;
        while(k>0){
            s.pop();
            k--;
        }
        
        while(!s.empty()){
            ans += nums[s.top()];
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        string finalAns = "";
        int flag = 0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0'){
                flag = 1;
            }
            if(flag ==1 ){
                finalAns+=ans[i];
            }
        }        
        if(finalAns == ""){
            return "0";
        }
        return finalAns;
        
    }
};