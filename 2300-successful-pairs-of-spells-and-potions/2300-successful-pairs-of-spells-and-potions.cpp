class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> res;
        for(int i=0;i<spells.size();i++){
            long long temp = success/spells[i];
            if(success%spells[i] !=0){
                temp++;
            }

            int index = lower_bound(potions.begin(),potions.end(),temp)-potions.begin();
            
            res.push_back(potions.size()-index);
        }

        return res;
    }
};