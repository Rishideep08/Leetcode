class Solution {
public:

    bool checkPalindrome(string str,int i,int j){
        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    vector<vector<string>> func(string str,int index){
        if(index == str.size()){
            vector<vector<string>> ans;
            vector<string> temp;
            ans.push_back(temp);
            return ans;
        }
        cout<<index<<endl;
        vector<vector<string>> ans;
        for(int i=index;i<str.size();i++){
            if(checkPalindrome(str,index,i)){
                string temp = str.substr(index,i-index+1);
                vector<vector<string>> temp1 = func(str,i+1);
                for(int i1=0;i1<temp1.size();i1++){
                    vector<string> temp2;
                    temp2.push_back(temp);
                    for(int j=0;j<temp1[i1].size();j++){
                        temp2.push_back(temp1[i1][j]);
                    }
                    ans.push_back(temp2);
                }   
            }
        }
        return ans;

    }

    vector<vector<string>> partition(string s) {
        return func(s,0);
    }
};