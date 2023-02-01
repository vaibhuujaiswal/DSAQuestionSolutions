//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long sumOfSeries(long long N) {
        long long sum = 0;
        value(N,sum);
        return sum;
    }
    
    long long value(long long N, long long &sum){
        if (N <= 0){
            return sum;
        }
        sum += (N*N*N);
        return value(N-1, sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.sumOfSeries(N) << "\n";
    }
}
// } Driver Code Ends