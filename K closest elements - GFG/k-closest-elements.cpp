//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        int right = binarySearch(arr,n,x);

        int left = right-1;
        vector<int> output;
        int count = k;
        while (left >= 0 && right < n && count > 0){
            if (arr[left] == x){
                left--;
                continue;
            }
            if (arr[right] == x){
                right++;
                continue;
            }
            if (abs(arr[left] - x) < abs(arr[right] - x)){
                output.push_back(arr[left]);
                count--;
                left--;
            }else if (abs(arr[left] - x) > abs(arr[right] - x)){
                output.push_back(arr[right]);
                count--;
                right++;
            }else{
                output.push_back(arr[right]);
                count--;
                right++;
            }
        }
        
        while (left >= 0 && count > 0){
            if (arr[left] == x){
                left--;
                continue;
            }
            output.push_back(arr[left]);
            count--;
            left--;
        }
        
        while (right < n && count > 0){
            if (arr[right] == x){
                right++;
                continue;
            }
            output.push_back(arr[right]);
            count--;
            right++;
        }
        
        return output;
    }

    int binarySearch(vector<int> arr, int n, int x){ //to find the crossover points
        int l = 0;
        int r = n-1;
        while (l < r){
            int m = l + (r-l)/2;
            if (arr[m] == x) return m;
            if (arr[m] < x){
                l = m+1;
            }else{
                r = m;
            }
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends