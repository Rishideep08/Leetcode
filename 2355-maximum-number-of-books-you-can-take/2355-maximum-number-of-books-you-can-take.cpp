class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        long long int  n = books.size();
        stack<long long int > s;
        if(n==0){
            return 0;
        }
        vector<long long int > dp(n+1,0);
        dp[0] = books[0];
        s.push(0);
        for(long long int  i=1;i<n;i++){
            long long int  end = i;
            if(books[end-1] <books[end]){
                dp[end] =  books[end]+dp[end-1];
            }else{
                while(!s.empty() && books[end]-end+s.top()>0 && books[s.top()]>books[end]-end+s.top()){
                    // cout<<s.top()<<endl;;
                    s.pop();
                }
                long long int elems = 0;
                if(s.empty()){
                    elems = end+1;
                }else{
                    // cout<<"Hi"<<endl;
                    elems = end-s.top();
                }
                // cout<<end<<" "<<elems<<endl;
                if(elems>=books[end]){
                    long long int temp = books[end];
                    dp[end] = (temp*(temp+1)/2);
                }else{
                    long long int  n = books[end]-elems;
                    long long int temp = books[end];
                    dp[end] = ((temp*(temp+1))/2) - (n*(n+1)/2);
                    if(!s.empty())
                        dp[end] = dp[end] + dp[s.top()];
                }
            }
            s.push(end);
        }
        long long int  maxVal = dp[0];
        for(long long int  i=0;i<n;i++){
            // cout<<dp[i]<<endl;
            maxVal = max(dp[i],maxVal);
        }
        return maxVal;
    }
};