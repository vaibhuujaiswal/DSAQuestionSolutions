//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        vector<vector<int>> v;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        // Your code goes here
        if (n < 4) return v;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                int l = j + 1;
                int r = n - 1;
                int sum = k - arr[j] - arr[i];
                while (l < r){
                    int currentSum =  arr[l] + arr[r];
                    if (currentSum < sum){l++;
                    }else if (currentSum > sum){
                        r--;
                    }else{
                        vector<int> temp(4,0);
                        temp[0] = arr[i];
                        temp[1] = arr[j];
                        temp[2] = arr[l];
                        temp[3] = arr[r];
                        v.push_back(temp);
                        while (l < r && arr[l] == temp[2]) ++l;
                        while (l < r && arr[r] == temp[3]) --r;
                    }
                }
            //room duplicates
            while (j + 1 < n && arr[j] == arr[j+1]) ++j;
            }
            while (i + 1 < n && arr[i] == arr[i+1]) ++i;
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends