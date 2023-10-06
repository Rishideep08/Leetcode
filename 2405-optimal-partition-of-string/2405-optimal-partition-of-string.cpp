class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int count = 0;
        int i=0;
        while(i<n){
            unordered_set<char> us;
            while(i<n){
                if(us.count(s[i])==0){
                    us.insert(s[i]);
                    i++;
                }else{
                    break;
                }
                
            }
            count++;
        }
        
        return count;
    }
};