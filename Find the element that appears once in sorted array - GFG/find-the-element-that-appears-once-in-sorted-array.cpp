//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int l = 0;
        int r = n - 1;
        if (n == 1){
            return arr[0];
        }
        while (l <= r){
            int m = l + (r-l)/2;
            if (l == m){
                if (arr[m] != arr[m+1]) return arr[m];
            }
            if (r == m){
                if (arr[m] != arr[m-1]) return arr[m];
            }
            
            if (l == r){
                return arr[l];
            }
            if (arr[m] != arr[m-1] && arr[m + 1] != arr[m]) return arr[m];
            
            if ((m+1) % 2 != 0){
                if (arr[m] == arr[m+1]){
                    l = m+2;
                    continue;
                }else{
                    r = m-1;
                    continue;
                }
            }else{
                if (arr[m] == arr[m-1]){
                    l = m+1;
                    continue;
                }else{
                    r = m-1;
                    continue;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends