class Solution {
public:
    class comp{
        public:
          bool operator()(const string &s1, const string &s2){
             return s1.size()<s2.size();
          }  
    };
    
    int longestStrChain(vector<string>& words) {
        
        unordered_map<string,int> um;
        sort(words.begin(),words.end(),comp());
        int ans = 0;
        int val = 0;
        for(int i=0;i<words.size();i++){
            string &in = words[i];
                val = 0;
                for(int j=0;j<in.size();j++){
                    string temp = in.substr(0,j)+in.substr(j+1);
                    if(um.find(temp)!=um.end()){
                        val = max(val,um[temp]);
                    } 
                }
                um[in] = val+1;
                ans = max(ans,val+1);
            
        }
        
        return ans;
        
    }
};