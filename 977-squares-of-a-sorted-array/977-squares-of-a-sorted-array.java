class Solution {
    public int[] sortedSquares(int[] nums) {
        int n=nums.length;
        int ans[]=new int [n];
        int a=0,b=n-1,x,y,i=n-1;
            while(a<=b)
            {
                x=nums[a]*nums[a];
                y=nums[b]*nums[b];
                if(x>y)
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