class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> us;
        int count =1;
        for(int i=0;i<s.size();i++){
            if(us.find(s[i]) != us.end()){
                count++;
                us.clear();
            }
            us.insert(s[i]);
        }
        return count;
    }
};