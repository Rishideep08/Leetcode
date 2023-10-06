class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int e1=INT_MAX,e2=INT_MAX, count1 = 0,count2 = 0;
        for(int i=0;i<n;i++){
            if(count1 == 0 && nums[i]!=e2){
                e1 = nums[i];
                count1++;
            }else if(count2 == 0 && nums[i]!=e1){
                e2 = nums[i];
                count2++;
            }
            else if(nums[i] == e1){
                count1++;
            }else if(nums[i] == e2){
                count2++;
            }else{
                count1--;
                count2--;
            }
            // cout<<e1<<" "<<count1<<endl;
            // cout<<e2<<" "<<count2<<endl;
            // cout<<"-----"<<endl;
        }
        
        count1 = 0;
        count2 = 0;
        for(int i=0;i<n;i++){
            if(e1 == nums[i]){
                count1++;
            }else if(e2 == nums[i]){
                count2++;
            }
        }
        vector<int> ans;
        if(count1>(n/3)){
            ans.push_back(e1);
        }
        if(count2>(n/3)){
            ans.push_back(e2);
        }
        
        return ans;
    }
    
};