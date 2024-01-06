class Solution {
public:
    
    
    
    
    string intToRoman(int num) {
        /*
        I = 1
        V = 5
        X = 10
        L = 50
        C = 100
        D = 500
        M = 1000
        */
        string res = "";
        int m = num/1000;
        while(m>0){
            res = res+'M';
            m--;
        }
        num = num%1000;
        if(num>=900){
            res = res+"CM";
            num = num - 900;
        }else if(num>=500){
            res = res+"D";
            num = num-500;
        }else if(num>=400){
            res = res+"CD";
            num = num-400;
        }
        int c = num/100;
        while(c>0){
            res = res+'C';
            c--;
        }
        num = num%100;
        if(num>=90){
            res = res+"XC";
            num = num - 90;
        }else if(num>=50){
            res = res+"L";
            num = num-50;
        }else if(num>=40){
            res = res+"XL";
            num = num-40;
        }
        
        int x = num/10;
        while(x>0){
            res = res+'X';
            x--;
        }
        num = num%10;
        if(num>=9){
            res = res+"IX";
            num = num - 9;
        }else if(num>=5){
            res = res+"V";
            num = num-5;
        }else if(num>=4){
            res = res+"IV";
            num = num-4;
        }
        
        while(num>0){
            res = res+'I';
            num--;
        }
        return res;
        
    }
};