class Solution {
public:
    int helper(string a,string b){
        int i=0,j=0;
        vector<int> arr(26,0),arr1(26,0);
        for(int i=0;i<a.size();i++){
            arr[a[i]-'a']++;
        }
        
        for(int i=0;i<b.size();i++){
            arr1[b[i]-'a']++;
        }
        
        for(int i=1;i<26;i++){
            arr[i]+=arr[i-1];
            arr1[i]+=arr1[i-1];
        }
        int ans = INT_MAX;
        for(int i=1;i<26;i++){
            int val = a.size();
            if(i!=0){
                val = val-arr[i-1];
            }
            int val1 = 0;
            if(i!=0){
                val1 = val1+arr1[i-1];
            }
            ans = min(ans,val+val1);
        }
        // cout<<ans<<endl;
        return ans;
    }
    
    int helper2(string a,string b){
        unordered_map<int,int> um;
        for(int i=0;i<a.size();i++){
            um[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
            um[b[i]]++;
        }
        
        int val = a.size()+b.size();
        int ans = INT_MAX;
        for(int i=0;i<26;i++){
            ans = min(ans,val-um['a'+i]);
        }
        // cout<<ans;
        
        return ans;
        
    }    
    
    
    int minCharacters(string a, string b) {
        
        return min(helper(a,b),min(helper(b,a),helper2(a,b)));
        
    }
};