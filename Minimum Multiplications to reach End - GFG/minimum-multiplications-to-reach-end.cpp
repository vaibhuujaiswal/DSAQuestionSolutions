//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        q.push({0,start});
        vector<int> visited(1e5,1e9);
        while (!q.empty()){
            auto it = q.front(); q.pop();
            int timesMultiplied = it.first;
            int value = it.second;
            for (auto i : arr){
                int multi = (i*value) % 100000;
                if (visited[multi] > (timesMultiplied + 1)){
                    visited[multi]  = timesMultiplied + 1;
                    if (end == multi) return visited[multi];
                    q.push({visited[multi],multi});
                }
            }
        }
        if (visited[end] == 1e9) return -1;
        return visited[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends