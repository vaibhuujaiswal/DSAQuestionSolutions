//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    int i = 0;
	    int j = 0;
	    if (n == 0 || n == 1){
	        return;
	    }
	    while (i < n && j < n){
	        if (arr[i] != 0){
	            i++;
	            if (j < i){
	                j = i;
	            }
	        }
	        
	        if (arr[i] == 0){
	            if (j > i && arr[j] != 0){
	                arr[i] = arr[j];
	                arr[j] = 0;
	            }else{
	                j++;
	            }
	        }
	        
	    }
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends