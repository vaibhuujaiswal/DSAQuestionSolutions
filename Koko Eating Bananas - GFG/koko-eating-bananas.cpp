//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int Solve(int N, vector<int>& piles, int H) {
        int maxi = INT_MIN;
        for (auto i : piles){
            maxi = max(maxi,i);
        }
        
        int l = 1;
        int r = maxi;
        while (l < r){
            int s = (l + r) >> 1;
            int value = check(piles,N,H,s);
            if (value < 0) {
                l = s + 1;
            }else{
                r = min(maxi,r);
                r = s;
            }
        }
        return r;
    }
    
    int check(vector<int>& piles,int n, int H, int speed){
        int totalHours = 0;
        int i = 0;
        while (i < n){

            totalHours += ceil((double)piles[i]/(double)speed);
            i++;
        }
        
        if (totalHours > H){
            return -1;
        }
        return totalHours;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends