class LRUCache {
public:
    int n;
    list<pair<int,int>> lru;
    unordered_map<int,list<pair<int,int>>::iterator> um;
    LRUCache(int capacity) {
        this->n = capacity;
    }
    
    int get(int key) {
       if(um.find(key) != um.end()){
           pair<int,int> kv = *um[key];
           
           lru.erase(um[key]);
           lru.push_front({key,kv.second});
           um[key] = lru.begin();
           return kv.second;
       }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(um.find(key) != um.end()){
            lru.erase(um[key]);
            um.erase(key);
        }
        
    
        
        lru.push_front({key,value});
        list<pair<int,int>>::iterator itr = lru.begin();
        um[key] = itr ;
        
        if(um.size()>n){
            um.erase(lru.rbegin()->first);
            lru.pop_back();
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */