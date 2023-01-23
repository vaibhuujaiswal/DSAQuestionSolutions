//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        for (int i = -1 * (n-1); i < n; i++){
            int valueofi = 0;
            valueofi = i;
            if (i < 0){
                valueofi = i*(-1);
            }
            for (int j = 0; j < valueofi; j++){
                cout << " ";
            }
            int tempn = n - valueofi;
            if (n == tempn){
                for (int j = 0; j < tempn; j++){
                cout << "* ";
            }
            cout << "" << endl;
            }
            for (int j = 0; j < tempn; j++){
                cout << "* ";
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends