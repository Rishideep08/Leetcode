class TimeMap {
    private :
        unordered_map<string,vector<pair<int,string>>> um;
    
    class comp{
        public :
            bool operator()(pair<int,string> a, pair<int,string> b){
                if(a.first < b.first){
                    return true;
                }
                return false;
            }
    };
    
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        um[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {
        
        if(um.find(key) == um.end() || timestamp < um[key][0].first){
            return "";
        }
        
    
        int index = upper_bound(um[key].begin(),um[key].end(),make_pair(timestamp,key),comp()) - um[key].begin();
        index--;
        
        if(index == -1){
            return "";
        }
        
        return um[key][index].second;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */