class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        if(n==2){
            return "11";
        }
        string temp = countAndSay(n-1);
        int i =0;
        string res="";
        int m = temp.size();
        while(i<m-1){
            int count = 1;
            while(i<m-1 && temp[i]==temp[i+1]){
                count++;
                i++;
            }
            res = res+to_string(count)+temp[i];
            i++;
        }
        
        if(temp[m-1] != temp[temp.size()-2]){
            res = res+to_string(1);
            res+=temp[temp.size()-1];
        }
        return res;
    }
};