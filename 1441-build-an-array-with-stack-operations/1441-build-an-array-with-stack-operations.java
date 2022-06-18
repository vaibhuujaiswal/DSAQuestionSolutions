

class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> stack = new ArrayList<String>(); 
        //consider index to start from 1
        int len = target.length;
        int x = 0; 
        for (int i = 1; i <= target[target.length - 1]; i++){
            stack.add("Push");
            if (target[x] == i){
                x++;
            }else{
                stack.add("Pop");
                }
            }
        return stack;
        }
}