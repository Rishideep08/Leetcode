/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<pair<vector<NestedInteger>::iterator,vector<NestedInteger>::iterator>> s;
    vector<NestedInteger> nestedList;
    int nextVal;
    NestedIterator(vector<NestedInteger> &nestedList) {
        if(nestedList.size()>0)
            s.push({nestedList.begin(),nestedList.end()});
        this->nestedList = nestedList;
    }
    int helper(){
        int val=0;
        if(s.empty()){
            return INT_MIN;
        }
        auto startItr = s.top().first;
        auto endItr = s.top().second;
        
        if(startItr->isInteger()){
            val = startItr->getInteger();
            startItr++;
            if(startItr == endItr){
                s.pop();
            }else{
                s.top().first = startItr;
            }
        }else{
            auto tempStartItr = startItr;
            startItr++;
            if(startItr == endItr){
                s.pop();
            }else{
                s.top().first = startItr;
            }
            // tempStartItr->getList();
            if(tempStartItr->getList().size()>0)
                s.push({tempStartItr->getList().begin(),tempStartItr->getList().end()});
            return helper();
        }
        
        
        return val;
    }
    
    int next() {
        return nextVal;
    }
    
    bool hasNext() {
        // if(s.empty()){
        //     return false;
        // }
        nextVal = helper();
        if( nextVal== INT_MIN){
            return false;
        }
        
//         auto startItr = s.top().first;
//         auto endItr = s.top().second;
        
//         if(startItr->isInteger()){
//             return true;
//         }else{
//             if(startItr->getList().size()>0){
//                 return true;
//             }
//             startItr++;
//             if(startItr == endItr){
//                 s.pop();
                
//             }
//         }
        
        
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */