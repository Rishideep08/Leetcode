class Solution {
public:
    int maxside;
    bool func(vector<int>&matchsticks,vector<int>&sides,int index){
        if(index == matchsticks.size()){
           return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        
    
        for(int j=0;j<4;j++){
            
            if(sides[j] + matchsticks[index]<=maxside){
                sides[j] += matchsticks[index];
                if(func(matchsticks,sides,index+1) == true){
                    return true;
                }
                sides[j] -= matchsticks[index];
            }
            
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n =matchsticks.size();
        vector<int> sides(4,0);
        int sum = 0;
        for(int i=0;i<matchsticks.size();i++){
            sum = sum + matchsticks[i];
        }
        if(sum%4 != 0){
            return false;
        }
        maxside = sum/4;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        return func(matchsticks,sides,0);
    }
};