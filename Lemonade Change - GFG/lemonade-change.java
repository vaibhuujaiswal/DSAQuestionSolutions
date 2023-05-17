//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            Solution obj = new Solution();
            boolean ans = obj.lemonadeChange(n, a);
            System.out.println(ans ? "True" : "False");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    static boolean lemonadeChange(int N, int bills[]) {
        int fiveDollar = 0;
        int tenDollar = 0;
        int twentyDollar = 0;
        for (int i = 0; i < N; i++){
            if (bills[i] == 5){
                fiveDollar++; 
            }else if (bills[i] == 10){
                tenDollar++;
                fiveDollar--;
            }else if (bills[i] == 20){
                twentyDollar++;
                if (tenDollar == 0){
                    fiveDollar -= 3;
                }else{
                    tenDollar--;
                    fiveDollar--;
                }
            }
            
            if (fiveDollar < 0 || tenDollar < 0 || twentyDollar< 0){
                return false;
            }
        }
        return true;
    }
}
