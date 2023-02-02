class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int n = arr.length;
        if(n<k){
            return 0;
        }
        int sum = 0;
        int count =0;
        for(int i=0;i<k;i++){
            sum = sum + arr[i];
        }
        if(threshold*k <= sum){
            count++;
        }
        for(int i=k;i<n;i++){
            sum = sum + arr[i]-arr[i-k];
            if(threshold*k <= sum){
                count++;
            }
        }
        return count;
    }
}