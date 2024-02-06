class Solution {
public:
    vector<int> prefix;
    Solution(vector<int>& w) {
        prefix = vector<int>(w.size(),0);
        prefix[0]=w[0];
        for(int i=1;i<w.size();i++){
          prefix[i] = prefix[i-1]+w[i];
        }
    }
    
    int pickIndex() {
        int target = rand()%(prefix.back());
        auto itr = upper_bound(prefix.begin(),prefix.end(),target);
        return itr-prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */