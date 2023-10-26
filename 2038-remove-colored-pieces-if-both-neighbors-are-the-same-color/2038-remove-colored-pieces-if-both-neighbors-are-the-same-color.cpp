class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int count1 = 0,count2 = 0;
        for(int i=1;i<n-1;i++){
            if(colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A'){
                count1++;
            }
            
             if(colors[i-1] == 'B' && colors[i] == 'B' && colors[i+1] == 'B'){
                count2++;
            }
            
        }
        
        if(count1>count2){
            return true;
        }
        return false;
    }
};