class LRUCache {
public:
    unordered_map<int,pair<int,list<int>::iterator>> kv;
    list<int> order;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(kv.find(key) == kv.end()){
            return -1;
        }
        
        order.erase(kv[key].second);
        
        order.push_back(key);
        
        // list<int>::iterator itr = prev(order.end());
        
        kv[key].second = prev(order.end());
        
        return kv[key].first;
    }
    
    void put(int key, int value) {
        if(kv.find(key) != kv.end()){
            order.erase(kv[key].second);            
        }else{
            if(n==0){
                int k = *order.begin();
                kv.erase(k);
                order.pop_front();
            }else{
                n--;
            }
        }
        
        order.push_back(key);

        kv[key].second = prev(order.end());
        kv[key].first = value;
        return;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */