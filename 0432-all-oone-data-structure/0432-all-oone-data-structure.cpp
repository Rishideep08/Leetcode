class AllOne {
    list<pair<int,unordered_set<string>>> ls;                                 
    unordered_map<string,list<pair<int,unordered_set<string>>>::iterator> mp; 
public:
    AllOne() { }
    
    void inc(string key) {
        if (!mp.count(key))
            mp[key] = ls.insert(ls.begin(),{0,{key}});                         
        auto itr = mp[key];               
        auto itrNext = next(itr);         
        if (itrNext==ls.end() || itr->first+1 < itrNext->first)               
            itrNext = ls.insert(itrNext,{itr->first+1,{}});
        itrNext->second.insert(key);   
        mp[key] = itrNext;             
        itr->second.erase(key);        
        if (itr->second.empty())       
            ls.erase(itr);
    }

    void dec(string key) {
        if (!mp.count(key))            
            return;
        auto itr = mp[key];            
        auto itrPrev = prev(itr);      
        mp.erase(key);                 
        if (itr->first>1) {            
            if (itr==ls.begin() || itr->first-1 > itrPrev->first)             
                itrPrev = ls.insert(itr,{itr->first-1,{}});
            itrPrev->second.insert(key);
            mp[key] = itrPrev;         
        }
        itr->second.erase(key);  
        if (itr->second.empty()) 
            ls.erase(itr);
    }
    
    string getMaxKey() {
        return mp.empty() ? "" : *ls.rbegin()->second.begin();
    }
    
    string getMinKey() {
        return mp.empty() ? "" : *ls.begin()->second.begin();                 
    }
};