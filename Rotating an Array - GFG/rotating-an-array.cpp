//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
// public:
//     void leftRotate(int arr[], int n, int d) {
// 	   //Method that uses extraspace a better version exists which you should work on
// 	   int rotationValue = d;
// 	   int rarr[n];
// 	   int count = 0;
// 	   for (int i = rotationValue; i < n; i++){
// 	       rarr[count] = arr[i];
// 	       count++;
// 	   }
	    
// 	   for (int i = 0; i < rotationValue; i++){
// 	       rarr[count] = arr[i];
// 	       count++;
// 	   }
	   
// 	   for (int i = 0; i < n; i++){
// 	       arr[i] = rarr[i];
// 	   }
//     }

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
	void leftRotate(int arr[], int n, int d) 
	{ 
	   int rk = d;
	   Reverse(arr, 0, rk-1);
	   Reverse(arr, rk, n - 1);
	   Reverse(arr, 0, n-1);
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}



// } Driver Code Ends