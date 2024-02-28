class Solution {
public:
    bool isStrobogrammatic(string num) {
       if(num == "0" || num=="1"||num=="8"){
           return true;
       }
        unordered_map<char,char> um;
        um['0'] = '0';
        um['1'] = '1';
        um['8'] = '8';
        um['6'] = '9';
        um['9'] = '6';
        string res = "";
        for(int i=0;i<num.size();i++){
            if(um.find(num[i]) == um.end()){
                return false;
            }
            res = res+um[num[i]];
        }
        reverse(res.begin(),res.end());
        if(res == num){
            return true;
        }
        return false;
    }
};