class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        set<int> onBulbs;
        int n=bulbs.size();
        if(n<2){
            return -1;
        }
        // onBulbs.insert(bulbs[0]);
        for(int i=0;i<bulbs.size();i++){
            auto u1 = onBulbs.upper_bound(bulbs[i]);
            if(u1 != onBulbs.end()){
                if(*u1-bulbs[i]-1==k){
                    return i+1;
                }
                if(u1 != onBulbs.begin()){
                    auto l1 = prev(u1);
                    if(bulbs[i]-*l1-1==k){
                        return i+1;
                    }
                }
            }else{
                if(u1 != onBulbs.begin()){
                    // cout<<"HI"<<endl;
                    auto l1 = prev(u1);
                    // cout<<*l1<<endl;
                    if(bulbs[i]-*l1-1==k){
                        return i+1;
                    }
                }
            }
            onBulbs.insert(bulbs[i]);
        }
        
        return -1;
    }
};