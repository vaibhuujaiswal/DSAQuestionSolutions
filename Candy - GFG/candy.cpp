//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int n, vector<int> &ratings) {
        vector<int> left(n,1);
        vector<int> right(n,1);
        for (int i = 1; i < n; i++){ //Left to right or L2R
            if (ratings[i-1] < ratings[i]){
                left[i] = left[i-1]+1;
            }
        }
        
        for (int i = n-2; i >= 0; i--){ //right to left or R2L
            if (ratings[i+1] < ratings[i]){
                right[i] = right[i+1]+1;
            }
        }
        int minimumCandies = 0;
        for (int i = 0; i < n; i++){
            minimumCandies += max(right[i],left[i]); //worst condition of max left and right;
        }
        return minimumCandies;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends