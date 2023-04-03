class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> temp;
        for(int i=0;i<position.size();i++){
            temp.push_back({(target-position[i]),(speed[i])});
        }
        sort(temp.begin(),temp.end());
        int i=0;
        int n = temp.size();
        int count =0;
        while(i<n){
            double head = temp[i].first/(1.0*temp[i].second);
            i++;
            count++;
            while(i<n && (temp[i].first/(1.0*temp[i].second))<=head){
                i++;
            }
        }

        return count;
        
    }
};