class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=0;
        int j=0;
        int carry =0;
        int n = num1.size();
        int m = num2.size();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        string res="";
        while(i<n && j<m){
            int val = (num1[i]-'0')+(num2[j]-'0')+carry;
            carry = val/10;
            val = val%10;
            char ch = val+'0';
            res += ch;
            
            
            i++;
            j++;
        }
        
        while(i<n){
            int val = (num1[i]-'0')+carry;
            carry = val/10;
            val = val%10;
            char ch = val+'0';
            res += ch;
            
            i++;
        }
        
        while(j<m){
            int val = (num2[j]-'0')+carry;
            carry = val/10;
            val = val%10;
            char ch = val+'0';
            res += ch;
            
            j++;
        }
        
        if(carry != 0){
            char ch = carry+'0';
            res += ch;
        }
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};