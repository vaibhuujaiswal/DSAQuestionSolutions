//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
// 2 2 4 4 8 5 5

class Solution{
public:	
	int search(int A[], int N){
	    if (N == 1){
	        return A[0];
	    }
	    int l = 0;
	    int r = N-1;
	    
	    if (A[l] != A[l+1]){
	            return A[l]; 
	        }
	        
	        if (A[r] != A[r-1]){
	            return A[r];
	        }
	    
	    while (l <= r){
	       
	        int m = l + (r - l)/2;
	        if (A[m] != A[m-1] && A[m] != A[m+1]){
	            return A[m];
	        }
	        if (m % 2 == 0){
	            if (A[m] == A[m + 1]){
	                l = m + 1;
	            }else{
	                r = m - 1;
	            }
	        }else{
	            if (A[m] == A[m-1]){
	                l = m + 1;
	            }else{
	                r = m - 1; 
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends