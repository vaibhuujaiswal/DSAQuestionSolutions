//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        vector<int> result;
        int count1 = 0;
        int count2 = 0;
        int f = INT_MAX; int s = INT_MAX;
        for (int i = 0; i < n; i++){
            if (f == nums[i]){
                count1++;
            }else if (s == nums[i]){
                count2++;
            }else if (count1 == 0){
                f = nums[i];
                count1++;
            }else if (count2 == 0){
                s = nums[i];
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < n; i++){
            if (f == nums[i]) count1++;
            else if (s == nums[i]) count2++;
        }
        
        if (count1 > n/3){
            result.push_back(f);
        }
        
        if (count2 > n/3){
            result.push_back(s);
            return result;
        }
        
        
        if (result.size() == 0){
            result.push_back(-1);
        }
        return result;
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
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends