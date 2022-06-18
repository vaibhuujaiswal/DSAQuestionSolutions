class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        int len = s.length();
        if (len == 0){  
            return 0;
        }
        int globalMax = 0;
        for (int i = 0; i < len; i++){
            if (s.charAt(i) == '('){
                stack.push(i);
            }else {
                stack.pop();
                if (stack.empty()){
                    stack.push(i);
                }else{
                    globalMax = Math.max(globalMax,i - stack.peek());
                }
            }
        }
        return globalMax;
    }
}

