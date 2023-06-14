class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j =0;
        for(int i=0;i<pushed.size();i++){
            s.push(pushed[i]);
            
            while(j<popped.size() && (!s.empty() &&  popped[j] == s.top())){
                s.pop();
                j++;
            }
        }
        
        if(s.empty()){
            return true;
        }
        return false;
    }
};