//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) { 
        /* 3 A 3
        2 ABA 2
        1 ABCBA
        0 ABCDCBA
        char c = 'A';
        */
        for (int i = 1; i <= n; i++){
            for (int j = 1; j < n-i+1; j++){
                cout << " ";
            }
            char c = 'A';
            for (int j = i-1; j > -1 * i - 1; j--){
                if (j == 0){
                    continue;
                }
                cout << c;
                if (j < 0){c--;}
                else {c++;}
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