class SnapshotArray {
public:
    int snap_id=0;
    vector<map<int,int>> list;
    SnapshotArray(int length) {
        list = vector<map<int,int>> (length); 
        for(int i=0;i<length;i++){
            list[i][snap_id] = 0;
        }
    }
    
    void set(int index, int val) {
         list[index][snap_id] = val;
        return;
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        map<int,int> &um = list[index];
        if(um.find(snap_id) != um.end()){
            return list[index][snap_id];
        }
        auto itr = um.upper_bound(snap_id);
        itr--;
       return itr->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */