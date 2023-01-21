//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        //use patter recognition, just write down stuff in numbers and they will talk back to you
        for (int i = 1; i < n+1 ; i++){
            for (int j = 0; j < n-i; j++){
                cout << " ";
            }
            int totalCount = ((i-1) * 2) + 1;
            for (int j = 0; j < totalCount; j++){
                cout << "*";
            }
            cout << "" << endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends