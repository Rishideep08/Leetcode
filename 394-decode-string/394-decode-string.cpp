class Solution {
public:
    string decodeString(string str) {
        int n = str.size();
        stack<int> s1;
        stack<string> s2;
        int k=0;
        string currString = "";
        for(int i=0;i<n;i++){
            if(isdigit(str[i])){
                k = k*10 + (str[i]-'0');
            }else{
                if(str[i] == '['){
                    s1.push(k);
                    s2.push(currString);
                    k=0;
                    currString = "";
                }else if(str[i] == ']'){
                    int val = s1.top();
                    s1.pop();
                    string temp = s2.top();
                    s2.pop();
                    while(val){
                        temp+=currString;
                        val--;
                    }
                    currString = temp;
                }else{
                    currString+=str[i];
                }
                
            }
        }
        return currString;
    }
};