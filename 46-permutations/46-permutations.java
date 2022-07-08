class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ls = new ArrayList<List<Integer>>();
        List<Integer> arr = new ArrayList<>();
        int n = nums.length;
        f(nums,ls,n,arr);
        return ls;
    }
    
    public void f(int[] nums,List<List<Integer>> ls,int n, List<Integer> arr){
        if (n == 0){
            if (arr.size() == nums.length){
                ls.add(new ArrayList<>(arr));
            }
            return;
        }
        
        for (int i = 0; i < nums.length; i++){
            List<Integer> blank = new ArrayList<>(arr);
            if (!blank.contains(nums[i])) blank.add(nums[i]);
            f(nums,ls,n-1,blank);
        }
        return;
    }
    
}