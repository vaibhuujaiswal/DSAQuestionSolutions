//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
        vector<int> result(N,-1);
        stack<int> stack;
        for (int i = 2 * N - 1; i >= 0; i--){
            while (!stack.empty() && arr[i % N] >= stack.top()){
                stack.pop();
            }
            
            if (i < N){
                if (stack.empty()){
                }else{
                    result[i] = stack.top();
                }
            }
            stack.push(arr[i % N]);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends