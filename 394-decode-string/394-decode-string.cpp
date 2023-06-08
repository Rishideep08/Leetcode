class Solution {
public:
    string decodeString(string str) {
        stack<string> s;
        int n = str.size();
        string ans;
        for(int i=0;i<n;i++){
            if(str[i] == ']'){
                string temp = "";
                while(!s.empty() && s.top() != "["){
                    temp = s.top()+temp;
                    s.pop();
                }
                
                s.pop();

                // reverse(temp.begin(),temp.end());

                int num = stoi(s.top());
                s.pop();
                string val = "";
                while(num>0){
                    val+=temp;
                    num--;
                }
                s.push(val);
            }else{
                string temp = "";
                while(i<n && (str[i]>='0' && str[i]<='9')){
                    temp += str[i];
                    i++;
                }
                if(temp == ""){
                    s.push(string(1,str[i]));
                }else{
                    s.push(temp);
                    i--;
                }
            }
        }
        while(!s.empty()){
            ans = s.top()+ans;
            s.pop();
        }
        return ans;
        
    }
};