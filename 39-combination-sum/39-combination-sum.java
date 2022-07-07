class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        f(0, candidates, target, list, new ArrayList<>());
        if (list.isEmpty()){
            System.out.println("yes");
        }
        return list;
    }
    public static void f(int i, int[] candidates, int target, List<List<Integer>> list, List<Integer> blank){
        if (i == candidates.length){
            if (target == 0){
                List<Integer> transfer = new ArrayList<>(blank);
                list.add(transfer);
            }
            return;
        }
        //using take/not take method we will further solve this question
        if (target >= candidates[i]){
            blank.add(candidates[i]);
            f(i,candidates, target - candidates[i],list,blank);
            blank.remove(blank.size() - 1);
        }
        f(i+1,candidates,target,list,blank);
    }
}