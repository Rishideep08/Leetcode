class Solution {
public:
    int minSwaps(vector<int>& data) {
        int count = 0;
        for(int i=0;i<data.size();i++){
            if(data[i] == 1){
                count++;
            }
        }
        
        int x =0;
        int ans = 0;
        for(int i=0;i<count;i++){
            if(data[i] == 1){
                x++;
            }
        }
        // if(x == count){
        //     return 0;
        // }
        ans = count-x;
        
        for(int i=count;i<data.size();i++){
            if(data[i-count] ==1 ){
                x--;
            }
            
            if(data[i] == 1){
                x++;
            }
            
            ans = min(ans,count-x);
        }
        
        return ans;
    }
};