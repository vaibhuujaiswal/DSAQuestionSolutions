// class Solution {
//     public boolean isPalindrome(String s) {
//         s = s.toLowerCase();
//         for (int i = 0;)
//     }
//     public boolean answer(String s){
//         if ((s.length() == 1) || s.length() == 0){
//             return true;
//         }else{
//             if (s.charAt(0) == s.charAt(s.length() - 1)) return answer(s.substring(1,s.length() - 1));
//         }
//         return false;
//     }
// }
              
class Solution {
    public boolean isPalindrome(String s) {
        s=s.toLowerCase();
        int start=0,end=s.length()-1;
        while(start<end){
            char a=s.charAt(start);
            char b=s.charAt(end);
            if(!Character.isLetterOrDigit(a)){
                start++;
            }else if(!Character.isLetterOrDigit(b)){
                end--;
            }else{
                if(a!=b){
                    return false;
                }
                start++;end--;
            }
        }
        return true;
    }
}