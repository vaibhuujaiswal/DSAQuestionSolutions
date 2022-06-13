class Solution {
    public static int[] searchRange(int[] nums, int B) {
        int[] arr = new int[2];
        // if (nums.length == 1){
        //     if (nums[0] == B){
        //         arr[0] = 0;
        //         arr[1] = 0;
        //         return arr;
        //     }else{
        //         arr[0] = -1;
        //         arr[1] = -1;
        //         return arr;
        //     }
        // }
        arr[0] = first(nums,B);
        if(arr[0] == -1){
            arr[0] = -1;
            arr[1] = -1;
            return arr;
        }
        arr[1] = last(nums,B,arr[0]);
        return arr;
    }
    
    public static int first(int[] A, int B){
        int left = 0;
        int right = A.length-1;
        while (left <= right){
            int m = (left + right)/2;
            if ((m == 0 || B > A[m-1]) && B == A[m]){
                return m;
            }else if (B > A[m]){
                left = m + 1;
            }else{
                right = m - 1;
                }
            }
            return -1;
        }
    
    
    public static int last(int[] A, int B,int left){
        int right = A.length-1;
        while (left <= right){
            int m = (left + right)/2;
            if ((m == A.length-1 || B < A[m+1]) && A[m] == B){
                return m;
            }else if (B >= A[m]){
                left = m + 1;
            }else{
                right = m - 1;
                }
            }
            return -1;
        }
    }