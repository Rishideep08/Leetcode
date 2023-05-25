class Solution {
private: 
    enum OperationType{
        LESS,
        GREATER,
        EQUAL,
    };
    vector<int> convertionFunc(string str,OperationType val){
        vector<int> ans;
        for(int j=0;j<26;j++){
            char ch = 'a'+j;
            int count = 0;
            for(int i=0;i<str.size();i++){
                if(val == LESS){
                    if(str[i]>ch){
                        count++;
                    } 
                }else if(val == GREATER){
                    if(str[i]<ch){
                        count++;
                    }   
                }else{
                    if(str[i]!=ch){
                        count++;
                    }
                }
                
            }
            ans.push_back(count);
        }
        return ans;
    }


    int minValFunc(string a, string b){
        vector<int> l1 = convertionFunc(a,LESS);
        vector<int> r1 = convertionFunc(b,GREATER);
        vector<int> e1 = convertionFunc(a,EQUAL);
        vector<int> e2 = convertionFunc(b,EQUAL);
        int minVal = INT_MAX;
        for(int i=0;i<26;i++){
            if(i!=25){
                int j = i+1;
                minVal = min(minVal,l1[i]+r1[j]);
            }
            minVal = min(minVal,e1[i]+e2[i]);
        }
        return minVal;
    }
public:
    int minCharacters(string a, string b) {
        return min(minValFunc(a,b),minValFunc(b,a));
    }
};