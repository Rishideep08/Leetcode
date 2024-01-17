class Solution {
public:
    int count = 0;
    int gcd(int a,int b){
        if(a<b){
            return gcd(b,a);
        }
        
        if(b==0){
            return a;
        }
        
        return gcd(a%b,b);
    }
    
    bool doGCD(vector<int>&comb){
        for(int i=0;i<comb.size();i++){
            if(gcd(comb[i],i+1) != 1){
                return false;
            }
        }
        return true;
    }
    void generatePermutations(int n,vector<int>&comb,vector<int>&visit,int index){
        if(comb.size() == n){
            count++;
            return;
        }
        
        for(int i=0;i<visit.size();i++){
            if(visit[i] == 0){
                if(gcd(index+1,i+1) == 1){
                    comb.push_back(i+1);
                    visit[i] = 1;
                    generatePermutations(n,comb,visit,index+1);
                    visit[i]=0;
                    comb.pop_back();
                }
            }

        }
        return;
    }
    int selfDivisiblePermutationCount(int n) {
        vector<int> comb,visit(n,0);
        generatePermutations(n,comb,visit,0);
        return count;
    }
};