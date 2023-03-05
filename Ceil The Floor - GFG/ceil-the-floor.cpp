//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    int min = arr[0];
    for (int i = 1; i < n; i++){
        if (min > arr[i]){
            min = arr[i];
        }
    }
    
    if (x > max) return make_pair(max,-1);
    if (x < min) return make_pair(-1, min);
    int fInd, cInd;
    int fDist = INT_MAX, cDist = INT_MAX;
 
    for (int i=0; i<n; i++)
    {
        // If current element is closer than
        // previous ceiling.
        if (arr[i] >= x && cDist > (arr[i] - x))
        {
        cInd = i;
        cDist = arr[i] - x;
        }
 
        // If current element is closer than
        // previous floor.
        if (arr[i] <= x && fDist > (x - arr[i]))
        {
        fInd = i;
        fDist = x - arr[i];
        }
    }
    
    return make_pair(arr[fInd],arr[cInd]);
}