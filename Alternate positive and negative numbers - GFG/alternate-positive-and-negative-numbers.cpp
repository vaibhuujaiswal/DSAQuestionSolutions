//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    int pos = 0;  //positive element
	    int neg = 0;  //negative element;
	    vector <int> final;
	    bool flag = true;
	    
	    for (int i = 0; i < n; i++){
	        if (arr[i] >= 0){
	            continue;
	        }else{
	            flag = false;
	        }
	    }
	    
	    if (flag == true){
	        return;
	    }else{
	        flag = true;
	    }
	    
	    
	    for (int i = 0; i < n; i++){
	        if (arr[i] < 0){
	            continue;
	        }else{
	            flag = false;
	        }
	    }
	    
	    if (flag == true){
	        return;
	    }else{
	        flag = true;
	    }
	    
	    
	    while (pos < n && neg < n){
	        while (arr[pos] < 0){
	            pos++;
	        }
	        while (arr[neg] >= 0){
	            neg++;
	        }
	        if (flag == true){
	            final.push_back(arr[pos]);
	            flag = false;
	            pos++;
	        }else{
	            final.push_back(arr[neg]);
	            flag = true;
	            neg++;
	        }
	    }
	    while (pos < n){
	        if (arr[pos] >= 0){
	            final.push_back(arr[pos]);
	        }
	        pos++;
	    }
	    while (neg < n){
	        if (arr[neg] < 0){
	            final.push_back(arr[neg]);
	        }
	        neg++;
	    }
	    
	    for (int i = 0; i < n; i++){
	        arr[i] = final[i];
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
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends