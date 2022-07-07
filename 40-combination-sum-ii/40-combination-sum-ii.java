class Solution {
    List<List<Integer>> result = new LinkedList<>();
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<Integer> list = new LinkedList<>();
        Arrays.sort(candidates);
        backtrack(0, candidates, 0, target, list);
        return result;
    }
    
    public void backtrack(int start, int[] candidates, int sum, int target, List<Integer> list) {
        if(sum == target) {
            result.add(new ArrayList(list));
            return;
        }
        if(sum > target) {
            return;
        }
        for(int i = start; i < candidates.length; i++) {
            if(i > start && candidates[i] == candidates[i - 1]) {
                continue;
            } else {
                list.add(candidates[i]);
                backtrack(i + 1, candidates, sum + candidates[i], target, list);
                list.remove(list.size() - 1);  
            }
        }
    }
}