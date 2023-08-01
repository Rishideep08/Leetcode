class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        set<int> onBulbs;
        for(int i=0;i<bulbs.size();i++){
            onBulbs.insert(bulbs[i]);
            auto u1 = onBulbs.upper_bound(bulbs[i]);
            auto l1 = onBulbs.lower_bound(bulbs[i]);
            if(u1 != onBulbs.end()){
                if(*u1-bulbs[i]-1==k){
                    return i+1;
                }
            }
            
            if(l1 != onBulbs.begin()){
                l1 = prev(l1);
                if(bulbs[i]-*l1-1==k){
                    return i+1;
                }
            }    
        }
        
        return -1;
    }
};