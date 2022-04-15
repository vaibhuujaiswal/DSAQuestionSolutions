class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        String s1 = strs[0];
        for (int i = 1; i < n; i++){
            String s2 = strs[i];
            int n1 = s1.length();
            int n2 = s2.length();
            String result = "";
            int len = 0;
            while ((n1 != len) && (n2 != len)){
                if (s1.charAt(len) == s2.charAt(len)){
                    result += s1.charAt(len);
                    len++;
                }else{
                    break;
                }
            }
            s1 = result;
        }
        return s1;
    }
}