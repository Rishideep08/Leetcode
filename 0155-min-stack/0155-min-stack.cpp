class MinStack {
public:
    int minVal = INT_MAX;
    stack<string> s;
    MinStack() {
        
    }
    
    void push(int val) {
        string temp = to_string(val)+"_"+to_string(minVal);
        s.push(temp);
        minVal = min(minVal,val);
    }
    
    void pop() {
        if(!s.empty()){
           string temp =  s.top();
            s.pop();
           int i = temp.find("_");
            // int val = stoi(temp.substr(0,i));
            int oldminVal = stoi(temp.substr(i+1));
            minVal = oldminVal;
        }
    }
    
    int top() {
        if(!s.empty()){
           string temp =  s.top();
           int i = temp.find("_");
            int val = stoi(temp.substr(0,i));
            return val;
            // int oldminVal = stoi(temp.substr(i+1));
            // minVal = oldminVal;
        }
        return -1;
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */