//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());

        int l = 1;
        int r = stalls[n-1] - stalls[0];
        int ans = -1;
        while (l <= r){
            int m = (l + r) >> 1;
            if (checkfunction(m,stalls,k,n)){
                ans = m;
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return ans;
    }
    
    bool checkfunction(int m, vector<int> &stalls,int k, int n){
        int lastIndex = 0;
        int cowCount = 1;
        for (int i = 1; i < n; i++){
            if (stalls[i] - stalls[lastIndex] >= m){
                cowCount++;
                lastIndex = i;
            }
            if (cowCount == k) return true;
        }
        if (cowCount == k) return true;
        else return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends