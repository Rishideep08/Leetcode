class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // unordered_map<int,int> um;
        // for(int i=0;i<people.size();i++){
        //     um[people[i]]++;
        // }
        
        sort(people.begin(),people.end());
        
        int i=0;
        int j=people.size()-1;
        int count = 0;
        while(i<=j){
            while(i<j && (limit-people[i])<people[j]){
                j--;
                count++;
            }
            count++;
            i++;
            j--;
        }
        
        return count;
        
        
        
        
    }
};