class Solution {
    public int strStr(String haystack, String needle) {
        int h = haystack.length();
        int n = needle.length();
        if (h == 0 || n == 0) return 0;
        if (h == 1 && n == 1){
            if (haystack.equals(needle)) return 0;
            else return -1;
        }
        for (int i = 0; i < h-n + 1; i++){
            System.out.println(haystack.substring(i,i + (n)));
            if (haystack.substring(i,i + (n)).equals(needle)) return i;
        }
        return -1;
    }
}