class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator> um;
    list<pair<int,int>> lru;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(um.find(key) == um.end()){
            return -1;
        }
        
        auto itr = um[key];
        int val = itr->first;
        lru.erase(itr);
        lru.push_back({val,key});
        um[key] = prev(lru.end());
        return val;
    }
    
    void put(int key, int val) {
        if(um.find(key) == um.end()){
            if(lru.size()==n){
                um.erase(lru.front().second);
                lru.pop_front();    
            }
            lru.push_back({val,key});
             um[key] = prev(lru.end());
        }else{
            auto itr = um[key];
            lru.erase(itr);
            lru.push_back({val,key});
            um[key] = prev(lru.end());
        }
        
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */