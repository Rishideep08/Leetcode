class LFUCache {
private:
    int minFreq;
    int n;
    class Node{
        public:
        int freq;
        int val;
        list<int>::iterator itr;
        Node(int val){
            this->freq = 1;
            this->val = val;
            this->itr = list<int>::iterator();
        }
    };
    unordered_map<int,Node*> kv;
    unordered_map<int,list<int>> freq_list;
    
    
    void deleteFunc(int freq,list<int>::iterator itr){
        list<int> &temp = freq_list[freq];
        temp.erase(itr);
        if(temp.size() == 0){
            if(freq == minFreq){
                minFreq++;
            }
            freq_list.erase(freq);
        }
    }
    
    list<int>::iterator addFunc(int freq,int key){
        freq_list[freq].push_back(key);
        list<int>::iterator itr = freq_list[freq].end();
        itr--;
        return itr;
    }
    
    
    int deleteMinFreq(){
        list<int> &temp = freq_list[minFreq];
        int key=*temp.begin();
        temp.pop_front();
        if(temp.size() == 0){
            freq_list.erase(minFreq);
            minFreq = minFreq+1;
        }
        return key;
        
    }
    
public:
    LFUCache(int capacity) {
        this->minFreq = 1;
        this->n = capacity;
    }
    
    
    int get(int key) {
        if(kv.find(key) == kv.end()){
            return -1;
        }
        deleteFunc(kv[key]->freq,kv[key]->itr);
        kv[key]->itr = addFunc(kv[key]->freq+1,key);
        kv[key]->freq = kv[key]->freq + 1;
        return kv[key]->val;    
    }
    
    void put(int key, int value) {
        if(kv.find(key) != kv.end()){
            deleteFunc(kv[key]->freq,kv[key]->itr);
            kv[key]->itr = addFunc(kv[key]->freq+1,key);
            kv[key]->freq = kv[key]->freq + 1;
            kv[key]->val = value;
            return;
        }
        
        if(n==0){
            int key = deleteMinFreq();
            delete kv[key];
            kv.erase(key);
        }else{
            n--;
        }
        Node* node = new Node(value);
        node->itr = addFunc(1,key);
        kv[key] = node;
        minFreq = 1;

        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */