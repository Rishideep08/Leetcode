class LFUCache {
public:
    unordered_map<int,pair<int,list<pair<int,int>>::iterator>> keyToFreq;
    unordered_map<int,list<pair<int,int>>> freqToKeys;
    
    int n;
    int minFreq;
    LFUCache(int capacity) {
        n = capacity;
    }
    
    void deleteFun(int oldFreq,int key){
        freqToKeys[oldFreq].erase(keyToFreq[key].second);
        if(freqToKeys[oldFreq].size() == 0){
            freqToKeys.erase(oldFreq);
            if(oldFreq == minFreq){
                minFreq++;
            }
        }
    }
    
    void update(int newFreq,int key,int value){
        freqToKeys[newFreq].push_back({key,value});
        keyToFreq[key].second = prev(freqToKeys[newFreq].end());
    }
    
    void deleteLeastFreq(){
        int key = freqToKeys[minFreq].front().first;
        keyToFreq.erase(key);
        freqToKeys[minFreq].erase(freqToKeys[minFreq].begin());
        if(freqToKeys[minFreq].size() == 0){
            freqToKeys.erase(minFreq);
        }
    }
    
    int get(int key) {
        if(keyToFreq.find(key) != keyToFreq.end()){
            int oldFreq = keyToFreq[key].first;
            int value = keyToFreq[key].second->second;
            keyToFreq[key].first = keyToFreq[key].first+1;
            deleteFun(oldFreq,key);
            update(oldFreq+1,key,value);
            return keyToFreq[key].second->second;
        }
        
        return -1;
        
    }
    
    void put(int key, int value) {
        if(keyToFreq.find(key) != keyToFreq.end()){
            int oldFreq = keyToFreq[key].first;
            keyToFreq[key].first = keyToFreq[key].first+1;
            // keyToFreq[key][1] = value;
            deleteFun(oldFreq,key);
            update(oldFreq+1,key,value);
        }else{
            if(keyToFreq.size() == n){
                deleteLeastFreq();
            }
            keyToFreq[key].first = 1;
            update(1,key,value);
            minFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */