class Solution {
    public int[] sortedSquares(int[] nums) {
        int n=nums.length;
        int ans[]=new int [n];
        int a=0,b=n-1,x,y,i=n-1;
            while(a<=b)
            {
                x=nums[a]*nums[a];
                y=nums[b]*nums[b];
                if(Math.abs(nums[a]) > Math.abs(nums[b]))
                {
                    ans[i--]=x;
                    a++;
                }
                else
                {
                    ans[i--]=y;
                    b--;
                }
            }
        return ans;
    }
}