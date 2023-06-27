class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        priority_queue<int> pq;
        vector<int> temp(nums.size(),0);
        for(int i=0;i<nums.size();i++){    
            if(pq.size()==k && nums[i]>pq.top()){
                temp[i] = 1;
            }
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        // for(int i=0;i<nums.size();i++){
        //     cout<<temp[i]<<" ";
        // }
        // cout<<endl;
        while(!pq.empty()){
            pq.pop();
        }
        for(int i=nums.size()-1;i>=0;i--){  
            if(pq.size()==k && nums[i]>pq.top()){
                if(temp[i] == 1){
                    temp[i] = 2;
                }
            }
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        // for(int i=0;i<nums.size();i++){
        //     cout<<temp[i]<<" ";
        // }
        // cout<<endl;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(temp[i] == 2){
                count++;
            }
        }
        
        return count;
    }
};