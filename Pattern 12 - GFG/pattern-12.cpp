//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution { // 8 6 4
  public:
    void printTriangle(int n) {
        int total = n * 2 - 2;
        int subtract = 0;
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < i+1; j++){
                cout << j << " ";
            }
            for (int j = 0; j < total; j++){
                cout << "  ";
            }
            total = total - 2;
            for (int j = i; j > 0; j--){
                cout << j << " ";
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