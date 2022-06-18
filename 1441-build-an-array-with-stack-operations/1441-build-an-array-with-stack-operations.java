class Solution {
    public List<String> buildArray(int[] target, int n) {
        // List<String> stack = new ArrayList<String>();
        // int x = 1;
        // for (int i = 0; i < target.length; i++){
        //     stack.add("Push");
        //     if (target[i] != x){
        //         stack.add("Pop");
        //         stack.add("Push");
        //     }
        //     x++;
        // }
        // return stack;
            List<String> list = new ArrayList<>();
        int j = 0;
    for(int i = 1; i <= target[target.length-1]; i++){
        list.add("Push");        
        if(target[j]!=i)
            list.add("Pop");
        else
            j++;
    } 
    return list;
}
    }
