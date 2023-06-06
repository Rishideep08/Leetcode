class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size()<=2){
            return true;
        }
        unordered_map<int,int> um;
        int firstVal = min(arr[0],arr[1]);
        int secondVal = max(arr[0],arr[1]);
        um[arr[0]]++;
        um[arr[1]]++;
        for(int i=2;i<arr.size();i++){
            if(arr[i]<firstVal){
                secondVal = firstVal;
                firstVal = arr[i];
            }else if(arr[i]<secondVal){
                secondVal = arr[i];
            }
            um[arr[i]]++;
        }
        int d = secondVal-firstVal;
        int x = firstVal;
        // cout<<firstVal<<" "<<secondVal<<endl;
        while(um.size()>0){
            if(um.find(x)==um.end()){
                return false;
            }
            um[x]--;
            if(um[x] ==0){
                um.erase(x);
            }
            x = x+d;
            // c
        }
        return true;
        
    }
};