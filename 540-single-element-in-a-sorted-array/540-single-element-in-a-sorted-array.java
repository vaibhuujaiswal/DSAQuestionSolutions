class Solution {
    public int singleNonDuplicate(int[] nums) {
    //     int n = nums.length;
    //     int l = 0;
    //     int r = n - 1;
    //     while (l <= r){
    //         int m = (l + r)/2;
    //         if (nums[m] != nums[m + 1] || nums[m] != nums[m - 1]){
    //             return nums[m];
    //         }else if (nums[m] == nums[m - 1]) {
    //             if ((m-l)%2 == 1){
    //                 if (l == m-2){
    //                     return nums[l];
    //                 }
    //                 r = m-2;
    //             }else{
    //                 l = m+1;
    //             }
    //         }else if (nums[m] == nums[m + 1]){
    //             if ((r-m)%2 == 1){
    //                 if (r == m+2){
    //                     return nums[r];
    //                 }
    //                 l = m + 2;      
    //             }
    //             else{
    //                 r = m-1;
    //             }
    //         }
    //     }
    //     return -1;
    // }
        
        int low = 0;
        int high = nums.length - 2;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid % 2 == 0) {
                // Checking whether we are in right half
                if (nums[mid] != nums[mid + 1]) 
                    
                    //Shrinking the right half
                    high = mid - 1; 
                else
                    // Shrinking the left half
                    low = mid + 1; 
            } else {
                // Checking whether we are in right half
                if (nums[mid] == nums[mid + 1])
                    //Shrinking the right half
                    high = mid - 1; 
                else
                    // Shrinking the left half
                    low = mid + 1; 
            }
        }
        return nums[low];
}
}

