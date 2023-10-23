class Solution {
public:
    bool func(string s1,string posStr){
        int i=0;
        int n = s1.size();
        int k = posStr.size();
        int d1 = n/k;
        if(n%k != 0){
            return false;
        }
        while(i<n){
            string temp1 = s1.substr(i,k);
            // cout<<"HI "<<temp1<<endl;
            i = i+k;
            if(temp1 != posStr){
                return false;
            }
        }
        return true;
    }
    bool check(string s1,string s2,string posStr){
        bool temp1 =   func(s1,posStr);
        bool temp2 =  func(s2,posStr);
        // cout<<temp1<<" "<<temp2<<endl;
        return temp1 & temp2;
    }
    string helper(string s1,string s2){
        string posStr;
        int n=s2.size();
        int m = s1.size();
        for(int i=n;i>0;i--){
            posStr = s2.substr(0,i);
            // cout<<posStr<<endl;
            if(check(s1,s2,posStr)){
                return posStr;
            }
        }
        return "";
        
    }
    
    string gcdOfStrings(string str1, string str2) {
        if(str1.size()>str2.size()){
            return helper(str1,str2);
        }
            return helper(str2,str1);
    
    }
};