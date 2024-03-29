class RandomizedSet {
public:
    unordered_set<int> us;
    RandomizedSet() {
         
    }
    
    bool insert(int val) {
        if(us.find(val) == us.end()){
            us.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(us.find(val) != us.end()){
            us.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int i = (int)(rand()%us.size());
        auto itr = us.begin();
        advance(itr,i);
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */