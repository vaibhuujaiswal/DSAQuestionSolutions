class Solution {
    public boolean isValid(String s) {
        if (s.isEmpty()) return true;
        Stack<Character> stack = new Stack<>();
        for (char i : s.toCharArray()){
            if (i == '{' || i == '[' || i == '(') stack.push(i);
            else {
                if (stack.empty()) return false;
                else{
                    if (i == '}' && stack.peek() == '{'){
                        stack.pop();
                    }else if (i == ']' && stack.peek() == '['){
                        stack.pop();
                    }else if (i == ')' && stack.peek() == '('){
                        stack.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        return stack.empty();
    }
}