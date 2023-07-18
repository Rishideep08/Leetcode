class Solution {
public:
    void func(string &res,int x,char ch){
        for(int i=0;i<x;i++){
            res = res+ch;
        }
       
    }
    
    string originalDigits(string s) {
               string arr[] = {"zero","two","eight","three","four","five","six","seven","nine","one"}; 
        
        char arr1[] = {'z','w','g','t','u','f','x','s','i','o'}; 
        
        int arr2[] = {0,2,8,3,4,5,6,7,9,1};
        
        unordered_map<char,int> letters;
        string res = "";
        for(int i=0;i<s.size();i++){
            letters[s[i]]++;
        }
        vector<int>temp(10,0);
        // int x = letters[arr1[0]];
        // for(int j=0;j<arr[0].size();j++){
        //     letters[arr[0][j]]-=x;
        // }
        // temp[0] = x;
         for(int i=0;i<10;i++){
            int x = letters[arr1[i]];
            for(int j=0;j<arr[i].size();j++){
                letters[arr[i][j]]-=x;
            }
            temp[arr2[i]] = x;
        }
        
         // x = letters[arr1[9]];
         //    for(int j=0;j<arr[9].size();j++){
         //        letters[arr[9][j]]-=x;
         //    }
         //    temp[1] = x;
        
        for(int i=0;i<10;i++){
            // cout<<temp[i]<<endl;
            for(int j =0;j<temp[i];j++){
                char ch = '0'+i;
                res = res + ch;
            }
        }
        
    
        return res;
    }
};