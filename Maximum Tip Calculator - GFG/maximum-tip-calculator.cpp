//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    long long maxTip(int a[], int b[], int n, int x, int y) {
        // code here
        long long ans=0;
        vector<pair<int,int>> lookup;
        for(int i=0;i<n;i++){
            ans = ans + b[i];
            lookup.push_back({a[i]-b[i],i});
        }
        
        sort(lookup.begin(),lookup.end(),greater<pair<int,int>>());
        long long res = 0;
        if(y>=n){
            res = ans;
        }
        int i=0;
        while(i<lookup.size() && i<x){
            ans = ans + lookup[i].first;
            if(y>=n-i-1){
                res = max(res,ans);
            }
            i++;
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        Solution obj;
        auto ans = obj.maxTip(a, b, n, x, y);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends