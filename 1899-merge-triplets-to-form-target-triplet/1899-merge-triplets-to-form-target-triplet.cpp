class Solution {
public:
    void check(vector<vector<int>>& triplets, vector<int>& target,vector<int> &temp,int index){ 
        for(int i=0;i<triplets.size();i++){
            if(temp[i] == 1 && target[index]>=triplets[i][index]){
                if(target[index] == triplets[i][index]){
                    temp[triplets.size()] = 1;
                }
            }else{
                temp[i] = 0;
            }
        }
    }
    
    
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> temp(triplets.size()+1,1);
        for(int i=0;i<3;i++){
            temp[triplets.size()] = 0;
            check(triplets,target,temp,i);
            if(temp[triplets.size()] ==0){
                return false;
            }
        }
        vector<int> res;
        res.push_back(INT_MIN);
        res.push_back(INT_MIN);
        res.push_back(INT_MIN);
        for(int i=0;i<triplets.size();i++){
            if(temp[i] == 1){
                // cout<<i<<" "<<triplets[i][0]<<" "<<triplets[i][1]<<" "<<triplets[i][2]<<endl;
                res[0] = max(triplets[i][0],res[0]);
                res[1] = max(triplets[i][1],res[1]);
                res[2] = max(triplets[i][2],res[2]);
            }
        }
        
        cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
        
        if(res[0] != target[0] || res[1] != target[1]||res[2] != target[2])
            return false;
        return true;
    }
};