//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        int l = 0;
        int r = n-1;
        if (v[n-1] < x){
            return n-1;
        }
        if (v[l] > x){
            return -1;
        }

        while (l <= r){
            int m = l + (r - l)/2;
            if (v[m] == x) {
                return m;
            }
            if (v[m] > x) r = m - 1;
            else l = m + 1;
        }
        if (l >= r){
            return r-1;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends