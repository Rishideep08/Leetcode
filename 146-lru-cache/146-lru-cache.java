class LRUCache {
    LinkedHashMap<Integer,Integer> lhm;
    int n;
    public LRUCache(int capacity) {
        this.n = capacity;
        lhm = new LinkedHashMap<>(n,0.5f,true){
            @Override
            protected boolean removeEldestEntry(Map.Entry<Integer,Integer> entry){
                return size() > n;
            }
        };
    }
    
    public int get(int key) {
        return lhm.getOrDefault(key,-1);
    }
    
    public void put(int key, int value) {
        lhm.put(key,value);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */