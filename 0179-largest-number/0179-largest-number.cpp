class Solution {
public:
    static bool comp(string &a, string &b){
        if(a+b > b+a){
            return true;
        }
        
        return false;
    }
    string largestNumber(vector<int>& nums) {
       vector<string> temp;
        for(int num : nums){
            temp.push_back(to_string(num));
        }
        
        sort(temp.begin(),temp.end(),comp);
        if(temp[0] == "0"){
            return "0";
        }
        string res;
        for(int i=0;i<temp.size();i++){
            res = res + temp[i];
        }
        return res;
    }
};