/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> candidates = words;
        
        while(candidates.size()!=0){
            // int index = (rand()%(candidates.size()));
            int index = candidates.size()/2;
            string &word = candidates[index];
            int match = master.guess(word);
            if(match == 6){
                return;
            }
            
            vector<string> temp;
            for(int i=0;i<candidates.size();i++){
                int count =0;
                for(int j=0;j<6;j++){
                    if(candidates[i][j] == word[j]){
                        count++;
                    }
                }
                if(count == match){
                    temp.push_back(candidates[i]);
                }
            }
            candidates = temp;
        }
        return ;
        
    }
};