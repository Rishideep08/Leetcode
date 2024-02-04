class MovingAverage {
public:
    long long int sum =0;
    deque<int> dq;
    int n;
    MovingAverage(int size) {
       n=size;
    }
    
    double next(int val) {
        dq.push_back(val);
        sum = sum +val;
        if(dq.size()>n){
            int val = dq.front();
            dq.pop_front();
            sum = sum -val;
        }
        double res = (sum*1.0)/(dq.size());
        return res;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */