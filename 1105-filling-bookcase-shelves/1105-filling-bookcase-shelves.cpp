class Solution {
public:
    vector<int> dp;
    int helper(vector<vector<int>>& books, int shelfWidth,int index){
       int sum = 0;
        if(index == books.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        
        int val = INT_MAX;
        int maxHeight = INT_MIN;
        for(int i = index;i<books.size();i++){
            if((sum+books[i][0])>shelfWidth){
                break;
            }else{
                maxHeight = max(maxHeight,books[i][1]);
                val = min(val,maxHeight+helper(books,shelfWidth,i+1));
                sum = sum+books[i][0];
            }
        }
        dp[index] = val;
        return val;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        dp = vector<int>(books.size(),-1);
        return helper(books,shelfWidth,0);
    }
};