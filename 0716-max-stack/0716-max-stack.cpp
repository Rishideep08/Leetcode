class compareMax{
  public :
    bool operator()(int a, int b){
      return a>b;
  }  
};
class compareStack{
    public: 
  bool operator()(long long int a, long long int b){
      return a>b;
  }  
};

class MaxStack {
public:
    map<int,vector<long long int>,greater<int>> maxMap;
    map<long long int,int,greater<int>> stackMap;
    long long int i;
    MaxStack() {
        i=0;
    }
    
    void push(int x) {
        // if(maxMap.find(x) == maxMap.end()){
        //     vector<int> temp;
        //     maxMap.insert({x,temp});
        // }
        maxMap[x].push_back(i);
        stackMap[i] = x;
        i++;
    }
    
    int pop() {
        int key = stackMap.begin()->second;
        int stackIndex = stackMap.begin()->first;
        stackMap.erase(stackIndex);
        maxMap[key].pop_back();
        if(maxMap[key].size() == 0){
            maxMap.erase(key);
        }
        return key;
    }
    
    int top() {
         int key = stackMap.begin()->second;
        return key;
    }
    
    int peekMax() {
       return maxMap.begin()->first;
    }
    
    int popMax() {
        int key = maxMap.begin()->first;
        int stackIndex = (maxMap.begin()->second)[(maxMap.begin()->second).size()-1];
        stackMap.erase(stackIndex);
         maxMap[key].pop_back();
        if(maxMap[key].size() == 0){
            maxMap.erase(key);
        }

        return key;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */