class LRUCache {    
    int n ;
    LinkedHashMap<Integer,Integer> lhm;
    public LRUCache(int capacity) {
        lhm = new LinkedHashMap<>();
        this.n = capacity;
    }
    
    void helper(int key){
        Integer x = 
        
        lhm.remove(key);
    }
    
    public int get(int key) {
        if(!lhm.containsKey(key)){
            return -1;
        }
        int val = lhm.get(key);
        lhm.remove(key);
        lhm.put(key,val);
        return val;
    }
    
    public void put(int key, int value) {
        if(lhm.containsKey(key)){
            lhm.remove(key);
            lhm.put(key,value);
            return;
        }
        
        if(n==0){
            int x = lhm.keySet().iterator().next();
            lhm.remove(x);
        }else{
            n--;
        }
        
        lhm.put(key,value);
        
        return;
        
        
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */