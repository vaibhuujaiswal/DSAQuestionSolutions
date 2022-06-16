// class Solution {
//     public int singleNonDuplicate(int[] nums) {
//         int n = nums.length;
//         int l = 0;
//         int r = n - 1;
//         while (l <= r){
//             int m = (l + r)/2;
//             if (nums[m] != nums[m + 1] || nums[m] != nums[m - 1]){
//                 return nums[m];
//             }else if (nums[m] == nums[m - 1]) {
//                 if ((m-l)%2 == 1){
//                     if (l == m-2){
//                         return nums[l];
//                     }
//                     r = m-2;
//                 }else{
//                     l = m+1;
//                 }
//             }else if (nums[m] == nums[m + 1]){
//                 if ((r-m)%2 == 1){
//                     if (r == m+2){
//                         return nums[r];
//                     }
//                     l = m + 2;      
//                 }
//                 else{
//                     r = m-1;
//                 }
//             }
//         }
//         return -1;
//     }
// }

class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = 0;
        int l = 0, r = nums.length -1;
        while (l < r){
            int m = l + (r - l) / 2;
            if (m % 2 == 1) {
               m--;  
            }
            if (nums[m] == nums[m + 1]) {
                l = m + 2;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
}