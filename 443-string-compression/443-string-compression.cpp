class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 0;
        for(int i=0;i<chars.size();i++){
            int count = 1;
            while(i<chars.size()-1 && chars[i] == chars[i+1]){
                count++;
                i++;
            }
            if(count == 1){
                chars[j] = chars[i];
                j++; 
            }else{
                chars[j] = chars[i];
                j++;
                vector<int> temp;
                while(count !=0){
                    int rem = count%10;
                    count = count/10;
                    temp.push_back(rem);
                }
                for(int k=temp.size()-1;k>=0;k--){
                    chars[j] = '0'+temp[k];
                    j++;
                }
            }
        }
        return j;
    }
};