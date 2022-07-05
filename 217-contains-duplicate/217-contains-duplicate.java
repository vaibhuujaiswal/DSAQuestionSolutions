class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer,Integer> hm = new HashMap<>();
        for (int i : nums){
            if (!hm.containsKey(i)){
                hm.put(i,1);
            }else{
                return true;
            }
        }
        return false;
    }
}

