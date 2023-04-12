class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        if(n%groupSize != 0){
            return false;
        }
        map<int,int> um;
        
        for(int i=0;i<n;i++){
            um[hand[i]]++;
        }
        
        int count =0;
        map<int,int> ::iterator itr;
        while(count<n){
            itr = um.begin();
            int elem = itr->first;
            int groupElem = 0;
            while(groupElem<groupSize && um.find(elem) != um.end()){
               groupElem++; 
                count++;
                um[elem]--;
                if(um[elem] == 0){
                    um.erase(elem);
                }
                elem++;
            }
            if(groupElem != groupSize){
                return false;
            }
        }
        
        return true;
    }
};