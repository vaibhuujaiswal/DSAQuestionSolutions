//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int k) {
        return sum(cardPoints,k);
    }
    
    long long sum(vector<int> &cardPoints, int k){
        int n = cardPoints.size();
        int l = 0;
        int r = n;
        int count = 0;
        long long sum = 0;
        long long maxSum = 0;
        while (count <= k-1){
            r--;
            count++;
            sum += cardPoints[r];
        }
        maxSum = max(sum,maxSum);
        count = 0;
        // cout << maxSum << endl;
        while (l <= k-1 && r < n){
            sum -= cardPoints[r];
            sum += cardPoints[l];
            r++;
            l++;
            // cout << r << l << endl;
            count++;

            // cout << "sum " << sum << endl;

            maxSum = max(sum,maxSum);
            // cout << maxSum << endl;

        }
        return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends