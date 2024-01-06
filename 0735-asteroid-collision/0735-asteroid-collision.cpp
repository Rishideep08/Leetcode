class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++){
            if(s.empty()){
                s.push(asteroids[i]);
            }else{
                if(!(s.top()>0 && asteroids[i]<0)){
                    s.push(asteroids[i]);
                }else{
                    while(!s.empty() && (s.top()>0 && asteroids[i]<0) && (s.top()<abs(asteroids[i]))){
                        s.pop();       
                    }
                    if(s.empty()){
                        s.push(asteroids[i]);
                    }else{
                        if(s.top()<0){
                            s.push(asteroids[i]);
                        }else{
                            if(s.top() == abs(asteroids[i])){
                                s.pop();
                            }
                        }
                    }
                }
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};