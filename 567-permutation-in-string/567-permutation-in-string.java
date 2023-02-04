class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        HashMap<Character, Integer> hm = new HashMap<>();
        HashMap<Character, Integer> hm1 = new HashMap<>();
        for(int i=0;i<s1.length();i++){
            hm.put(s1.charAt(i),hm.getOrDefault(s1.charAt(i),0)+1);
            hm1.put(s2.charAt(i),hm1.getOrDefault(s2.charAt(i),0)+1);
        }
        // print(hm);
        // print(hm1);
        if(compare(hm,hm1) == true){
            return true;
        }
        for(int i=s1.length();i<s2.length();i++){
            hm1.put(s2.charAt(i-s1.length()),hm1.getOrDefault(s2.charAt(i-s1.length()),0)-1);
            if(hm1.get(s2.charAt(i-s1.length())) == 0){
                hm1.remove(s2.charAt(i-s1.length()));
            }
            hm1.put(s2.charAt(i),hm1.getOrDefault(s2.charAt(i),0)+1);
            // print(hm);
            // print(hm1);
            if(compare(hm,hm1) == true){
                return true;
            }
            
        }
        return false;
    }
    private boolean compare(HashMap<Character,Integer> hm1, HashMap<Character,Integer> hm2){
        return hm1.equals(hm2);
    }
    private void print(HashMap<Character,Integer> hm){
        for( Map.Entry<Character,Integer> entrySet : hm.entrySet()){
            System.out.println(entrySet);
        }
        System.out.println("Done with printing");
    }
}