class LRUCache {
public:
    list<pair<int,int>> lru;
    unordered_map<int,list<pair<int,int>>::iterator> um;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(um.find(key) == um.end()){
            return -1;
        }
        int val = um[key]->first;
        lru.erase(um[key]);
        lru.push_front({val,key});
        um[key] = lru.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(um.find(key) != um.end()){
            lru.erase(um[key]);
            um.erase(key);
        }
        if(um.size()==n){
            auto itr = prev(lru.end());
            int removeKey = itr->second;
            um.erase(removeKey);
            lru.pop_back(); 
        }
        lru.push_front({value,key});
        um[key] = lru.begin();
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */