class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> asc,des;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i == 0){
                asc.push_back(i);
                if(i!=sqrt(n))
                    des.push_back(n/i);
            }
        }
        if(asc.size()>=k){
            return asc[k-1];
        }
        int y = des.size()-1+asc.size()-k+1;
        if(y<0){
            return -1;
        }
        return des[y];
    }
};