//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
    void Reverse(int arr[], int l, int r){
    	while (l <= r){
    		int temp = arr[l];
    		arr[l] = arr[r];
    		arr[r] = temp;
    		l++;
    		r--;
    	}
    }
    
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	   int rk = k%n;
	   Reverse(arr, 0, rk-1);
	   Reverse(arr, rk, n - 1);
	   Reverse(arr, 0, n-1);
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
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends