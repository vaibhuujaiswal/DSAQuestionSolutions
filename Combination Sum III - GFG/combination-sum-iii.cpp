//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<vector<int>> combinationSum(int k, int n) {
        vector<int> arr(9);
        vector<vector<int>> output;
        if (n > 45) return output;
        for (int i = 1; i < 10; i++){
            arr[i-1] = i;
        }
        vector<int> temp;
        findComb(0, n, arr, output, k, temp);
        return output;
    }

    void findComb(int ind, int n, vector<int> &arr,  
    vector<vector<int>> &output, int &k, vector<int> temp){
        if (temp.size() == k and n == 0){
            output.push_back(temp);
            return;
        }
        if (ind == arr.size()) return;
        if (temp.size() >= k) return;

        findComb(ind+1,n,arr,output,k,temp);
        if (arr[ind] > n) return;
        temp.push_back(arr[ind]);
        findComb(ind+1,n - arr[ind],arr,output,k,temp);
        temp.pop_back();
        return;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends