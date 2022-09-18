class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        if (x==0) return true;
        int storex = x;
        int revx = 0;
        while (x > 0){
            revx = (revx*10) + (x % 10);
            x = x / 10;
        }
        if (storex == revx) return true;
        else return false;
    }
}