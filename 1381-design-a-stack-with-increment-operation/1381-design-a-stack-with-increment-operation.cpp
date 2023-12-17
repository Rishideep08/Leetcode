class CustomStack {
private: 
    vector<int> stack,map;
    int index;
public:
    CustomStack(int maxSize) {
        stack = vector<int>(maxSize,0);
        map = vector<int>(maxSize,0);
        index = -1;
    }
    
    void push(int x) {
        if(stack.size()-1 == index){
            return;
        }else{
            // cout<<x<<endl;
            index++;
            stack[index] = x;
        }
    }
    
    int pop() {
        if(index == -1){
            return -1;
        }
        int val = stack[index]+map[index];
        if(index != 0){
            map[index-1] += map[index];    
        }
        map[index] = 0;
        index--;
        return val;
    }
    
    void increment(int k, int val) {
        k = min(k-1,index);
        if(k>=0){
            map[k] += val;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */