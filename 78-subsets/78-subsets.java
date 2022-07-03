class Solution {
     public List<List<Integer>> subsets(int[] nums) {       
        return recSubsets(0, nums, new ArrayList<>(), new ArrayList<>());
    }
    
    List<List<Integer>> recSubsets(int i, int[] nums, List<Integer> prevSubSet, List<List<Integer>> res){
        if(i==nums.length){
            res.add(prevSubSet);
            return res;
        }
        
        List<Integer> extraSubSet = new ArrayList<>(prevSubSet);
        extraSubSet.add(nums[i]);
        
        recSubsets(i+1, nums, prevSubSet, res);
        recSubsets(i+1, nums, extraSubSet, res);
        
        return res;
    }
}
