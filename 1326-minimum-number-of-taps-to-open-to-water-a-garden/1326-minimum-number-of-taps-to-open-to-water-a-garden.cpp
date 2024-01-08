class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]<b[0]){
            return true;
        }
        if(a[0] == b[0]){
            return a[1]>b[1];
        }
        return false;
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> pairs;
        if(n == 0){
            return 0;
        }
        int ans = 0;
        for(int i=0;i<ranges.size();i++){
            pairs.push_back(vector<int>{max(i-ranges[i],0),min(i+ranges[i],n)});
        }
        
        sort(pairs.begin(),pairs.end(),comp);
        
        // for(int i=0;i<pairs.size();i++){
        //     for(int j=0;j<pairs[i].size();j++){
        //         cout<<pairs[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int maxCovered = pairs[0][0];
        int i=0;
        while(i<pairs.size()){
            if(pairs[i][0]-maxCovered>0){
                return -1;
            }
            int prevMaxCovered = maxCovered;
            // int index = -1;
            int flag = 0;
            while(i<pairs.size() && pairs[i][0]<=prevMaxCovered){
                // if(pairs[i][1]>maxCovered){
                //     index = max(index,i);
                // }
                maxCovered = max(pairs[i][1],maxCovered);
                i++;
                flag = 1;
            }
            // if(flag == 1){
            //     i--;
            // }
            // cout<<maxCovered<<" : "<<i<<endl;
            if(maxCovered>prevMaxCovered){
                // cout<<"tap on at "<<index<<endl;
                ans++;
            }
            
        }
        
        return ans;
    }
};