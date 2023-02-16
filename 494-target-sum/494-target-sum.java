class Solution {
    private HashMap<Integer,HashMap<Integer,Integer>> hm;
    private int count;
    
    private int fun(int i,int desiredSum,int[]nums){
        if(i==nums.length){
            // System.out.println(desiredSum);
            if(desiredSum == 0){
                return 1;
            }
            return 0;
        }
        if(hm.get(desiredSum)==null || hm.get(desiredSum).get(i) == null){
            int val = fun(i+1,desiredSum+nums[i],nums)+fun(i+1,desiredSum-nums[i],nums);
            if(hm.get(desiredSum) == null){
                hm.put(desiredSum,new HashMap<>());
            }
            hm.get(desiredSum).put(i,val);
        }
        return hm.get(desiredSum).get(i);
    }
    
    public int findTargetSumWays(int[] nums, int target) {
        hm = new HashMap<>();
        fun(0,target,nums);
        return hm.get(target).get(0);
    }
}