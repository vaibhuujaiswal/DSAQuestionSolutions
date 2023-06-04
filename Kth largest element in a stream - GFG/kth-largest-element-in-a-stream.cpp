//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        priority_queue<int,vector<int>, greater<int>> minheap;
        vector<int> output;
        for (int i = 0; i < n; i++){
            minheap.push(arr[i]);
            if (minheap.size() < k) {
                output.push_back(-1);
                continue;
            }
            if (minheap.size() > k){
                minheap.pop();
            }
            output.push_back(minheap.top());
        }
        return output;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends