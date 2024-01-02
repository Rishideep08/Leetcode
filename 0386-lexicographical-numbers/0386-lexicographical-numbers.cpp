class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int start = 1;
        while(start<=n){
            if(start*10<=n){
                ans.push_back(start);
                start = start*10;
            }else{
                int lastDigit = (start-(start/10)*10);
                int remain = 10-lastDigit;
                int prefix = start/10;
                start = prefix*10+lastDigit;
                while(remain>0 && start<=n){
                    ans.push_back(start);
                    start++;
                    remain--;
                }
                while(prefix%10 == 9){
                    prefix = prefix/10;
                }
                start = prefix+1;
                if(start ==1){
                    return ans;
                }
            }
        }
        return ans;
    }
};