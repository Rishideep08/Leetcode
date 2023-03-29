class Solution {
public:
    static bool comp(int a,int b){
        return a>b;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int count = 0;
        int zeros = 0;
        int extra = 0;
        int time = 1;
        vector<int> negatives;
        sort(satisfaction.begin(),satisfaction.end());
        for(int i=0;i<satisfaction.size();i++){
            if(satisfaction[i] > 0){
                extra = extra + satisfaction[i];
                count = count + satisfaction[i]*(time);
                time++;
            }else if(satisfaction[i] == 0){
                zeros++;
            }else{
                negatives.push_back(satisfaction[i]);
            }
        }
        count = count + (zeros)*extra;
        sort(negatives.begin(),negatives.end(),greater<int>());
        
        int maxVal = count;
        
        for(int i=0;i<negatives.size();i++){
            extra = extra +negatives[i];
            count = count + extra;
            // cout<<count<<endl;
            maxVal = max(maxVal,count);
        }
        
        return maxVal;
        
        
    }
};