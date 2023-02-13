//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	   //Method that uses extraspace
	   int rotationValue = k % n;
	   int rarr[n];
	   int count = 0;
	   for (int i = rotationValue; i < n; i++){
	       rarr[count] = arr[i];
	       count++;
	   }
	    
	   for (int i = 0; i < rotationValue; i++){
	       rarr[count] = arr[i];
	       count++;
	   }
	   
	   for (int i = 0; i < n; i++){
	       arr[i] = rarr[i];
	   }
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