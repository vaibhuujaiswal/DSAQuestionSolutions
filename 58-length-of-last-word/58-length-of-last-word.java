class Solution {
    public int lengthOfLastWord(String s)  {
        int n = s.length();
        int start = 0;
        boolean wal = true;
        char c = ' ';
        if (n == 0){
            return 0;
        }
        for (int i = n-1; i >= 0; i--){
            if (s.charAt(i) != c && wal) wal = false;
            
            if (!wal){
                start++;
                if (s.charAt(i) == c) return start-1;
            }
        }
        // System.out.println(start);
        // if (start == 0) return n;
        // else return start;
        return start;
    }
}