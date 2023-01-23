//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution {
  public:
    void printTriangle(int n) {
        int intcount = 0;
        for (int i = -1 * (n-1); i < n; i++){
            if (intcount == 0  && i == 0){
                intcount++;
            }
            int valueofi = 0;
            valueofi = i;
            if (i < 0){
                valueofi = i*(-1);
            }

            int tempn = n - valueofi;
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends