class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int excess = 0;
        int index = -1;
        for(int i=0;i<gas.length;i++){
            int val = gas[i]-cost[i];
            if(index == -1){
                index = i;
            }
            excess+=val;
            if(excess<0){
                excess = 0;
                index = -1;
            }
        }
        for(int i=0;i<index;i++){
            int val = gas[i]-cost[i];
            excess+=val;
            if(excess<0){
                return -1;
            }
        }
        return index;
    }
}